from Raspi_MotorHAT import Raspi_MotorHAT, Raspi_DCMotor  # 모터햇 
from smbus import SMBus
import math # 바퀴 둘레를 구하기 위한 라이브러리
from gpiozero import DistanceSensor, RotaryEncoder # 초음파센서, 로터리 엔코더
from gpiozero.tools import scaled_half
from Raspi_PWM_Servo_Driver import PWM # 서보모터
from threading import Timer, Lock # 타이머를 이용한 쓰레드 사용
from time import sleep 
import sys
import atexit # 프로그램 종료시 할당해제?
import RPi.GPIO as GPIO # 초음파센서 밑 서보모터제어

from PySide2.QtWidgets import * # Qt
from qt_ui import Ui_MainWindow # UI

class MyApp(QMainWindow, Ui_MainWindow):
    def __init__(self):
        super().__init__()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)

    def main(self):
        pass

    def go_qt(self):
        mid() # 중앙정렬 후
        go() # 직진
    def back_qt(self):
        mid() # 중앙정렬 후 
        back() # 후진 
    def right_qt(self):
        right(0) #우회전 / 0은 qt로 제어할때 호출 right 또는 left 함수를 호출했음을 구별하기위한 매개변수
    def left_qt(self):
        left(0)
    def stop_qt(self):
        stop() # 정지후
        mid() # 중앙정렬
    def autoDriveStart_qt(self):
        global autostop
        autostop = 0 # autostop이 1이면 autodrive함수의 while문을 탈출
        autodrive()
    def autoDriveExit_qt(self):
        global autostop
        autostop = 1


app = QApplication()
win = MyApp()

win.show()

# value

timer = None # checkdist 쓰레드 함수에 사용되는 타이머
timer2 = None # is_stop 쓰레드 함수에 사용되는 타이머
timer3 = None # checkfront 쓰레드 함수에 사용되는 타이머
lock = Lock()
target_y = 800 # autodrive 모드에서 사용되는 목적지의 y좌표
target_x = 200 # autodrive 모드에서 사용되는 목적지의 y좌표
my_y = 0  # 0,0 => 최초 위치 세팅 (RC카를 놓는 지점을  0,0으로 간주)
my_x = 0
dir = 3 # 최초 방향 왼쪽
autostop = 0 # autodrive 탈출을 위한 변수

dx = [0,0,-1,1] # 상(최초 보고있는 방향 기준 오른쪽) , 하(최초 보고있는 방향 기준 왼쪽) , 우(최초 보고있는 방향 기준 뒷쪽) , 좌(최초 보고있는 방향 기준 앞쪽)
dy = [1,-1,0,0]

dL = [3,2,0,1]  # 현재 방향에서 왼쪽방향 "인덱스"  ex) dL[현재방향 인덱스] = 현재방향 기준 왼쪽방향 인덱스
dR = [2,3,1,0]  # 현재 방향에서 오른쪽방향 "인덱스"

# hardware part
wheelR = 3 # 휠 반지름 3cm
pi = math.pi # 원주율
wheel_dist = 2 * wheelR * pi  # 바퀴의 둘레 = 1바퀴 굴렀을때의 이동거리

# distance sensor part
speed = 0 # 최초 속도
Rdissensor = DistanceSensor(23, 24) #Echo , Trig  // 오른쪽 초음파센서
Ldissensor = DistanceSensor(17, 27) # 왼쪽 초음파 센서
Fdissensor = DistanceSensor(5 , 6) # 아래 범퍼에 부착된 초음파 센서
FR_dist =0 # 오른쪽 초음파 센서가 측정한 전방 장애물 거리
FL_dist=0 # 왼쪽 초음파 센서가 측정한 전방 장애물 거리
L_dist = 0 # 왼쪽 초음파센서가 측정한 왼쪽 장애물 거리
R_dist = 0 # 오른쪽 초음파센서가 측정한 오른쪽 장애물 거리
F_dist = 0 # 범퍼에 부착된 전방 초음파 센서가 측정한 장애물 거리
stopit = 0 # RC카가 장애물등에 걸려 움직이지 못하고있는지 여부를 나타내는 변수

# motor part
mh = Raspi_MotorHAT(addr=0x6f) # 모터햇
myMotor = mh.getMotor(2) # 모터 포트
pwm = PWM(0x6F) # 앞바퀴축 서보모터 각도 제어
pwm.setPWMFreq(60)

# servomotor part
DUTY_MIN = 3 # 초음파 센서용 서보모터 설정
DUTY_MAX = 12

Rservo_pin = 15 # 오른쪽 서보모터 핀번호
Lservo_pin = 21 # 왼쪽 서보모터 핀번호

GPIO.setmode(GPIO.BCM) #서보모터들 설정
GPIO.setup(Lservo_pin,GPIO.OUT)
GPIO.setup(Rservo_pin,GPIO.OUT)

Lservo = GPIO.PWM(Lservo_pin,50)
Rservo = GPIO.PWM(Rservo_pin,50)
Lservo.start(0)
Rservo.start(0)

# encoder part
rotor = RotaryEncoder(16,12) # 5번째 바퀴에 연결된 로터리 엔코더 핀번호
step = 0 # 로터리 엔코더 돌아가는 1칸단위 누적
turncnt = 0 # 몇바퀴 돌았는지 
totaldist = 0 # 총 누적거리 방향상관없이
linedist = 0 # 현재 방향으로 움직인 거리 
stopdist = 0 # 움직임이 멈췄는지 판별할 기준 위치

def LposContDeg(deg):  # 왼쪽 서보모터 각도 변환
    duty = DUTY_MIN +(deg * (DUTY_MAX - DUTY_MIN) / 180)
    Lservo.ChangeDutyCycle(duty)

def RposContDeg(deg): # 오른쪽 서보모터 각도 변환
    duty = DUTY_MIN + (deg * (DUTY_MAX - DUTY_MIN) / 180)
    Rservo.ChangeDutyCycle(duty)

def turnOffMotors(): # 프로그램 종료시 모든 모터 할당해제, 쓰레드 타이머 중지, 종료 여부와 종료시 좌표 출력
    global timer, timer2, timer3
    mh.getMotor(1).run(Raspi_MotorHAT.RELEASE)
    mh.getMotor(2).run(Raspi_MotorHAT.RELEASE)
    mh.getMotor(3).run(Raspi_MotorHAT.RELEASE)
    mh.getMotor(4).run(Raspi_MotorHAT.RELEASE)
    timer.stop()
    timer2.stop()
    timer3.stop()
    print("exit!!")
    print("y: ", my_y, "x: ", my_x)

atexit.register(turnOffMotors) # ctrl + c 입력시 호출되는 할당해제 함수 실행 문

def is_stop(): # 6초마다 RC카가 멈춰있는지 판단하는 함수 쓰레드
    global totaldist, stopdist, stopit
    print(" is it stop?")
    if stopdist +0.1 >= totaldist >= stopdist - 0.1 : # 이전에 is_stop 함수가 실행됐을때 저장된 좌표랑 비교하여 변화가 없는경우 멈춰있다고 판단
        print(totaldist)
        print(stopdist)
        print("yes")
        lock.acquire() # mutex 역할
        stopit = 1 # 멈춰있음을 표시
        lock.release()
    else :
        stopit = 0 # 멈춰있지 않다고 표시
        print("NO")
    stopdist = totaldist
    global timer2
    timer2 = Timer(6,is_stop) # 6초후에 이 함수를 다시 호출하는 타이머 생성
    timer2.start() # 타이머 시작

# def caldist():
#     global turncnt, step, totaldist
#     step -= rotor.steps
#     rotor.steps = 0
#     if 1 <= step / 20:
#         turncnt += int(step / 20)
#         step %= 20
#     totaldist = turncnt * wheel_dist
#     timer = Timer(0.01, caldist)
#     timer.start()

def checkfront(): # 전방 장애물 거리 측정 함수 쓰레드
    global FL_dist , FR_dist, F_dist
    lock.acquire()
    FL_dist = Ldissensor.distance * 100
    FR_dist = Rdissensor.distance * 100
    F_dist =  Fdissensor.distance * 100
    # print("FL :",FL_dist)
    # print("FR :",FR_dist)
    # print("---------------")
    lock.release()
    global timer3
    timer3 = Timer(0.01, checkfront) # 0.01초후에 이 함수를 다시 호출하는 타이머 생성
    timer3.start() # 타이머 시작

def checkdist(): # 누적거리, 현재 좌표 계산 함수 쓰레드
    global turncnt, step, totaldist, linedist, my_x, my_y, dir
    step -= rotor.steps # 로터리 엔코더가 앞으로 구를때 -값을 반환
    rotor.steps = 0 # 현재 누적엔코더값을 step 변수에 넘겨주고 0으로 초기화 됨
    linedist = wheel_dist * step / 20 # 20step = 1바퀴 => 이 함수가 호출되고 다시 호출될때까지 누적 이동 거리
    my_y += dy[dir] * linedist # 방향배열이용해서 좌표 계산 단위 : cm
    my_x += dx[dir] * linedist
    totaldist += linedist # 방향 관계없이 총 누적거리 합산
    step = 0 # step 초기화 => 다음 이동거리 측정 준비
    global timer
    timer = Timer(0.01, checkdist)
    timer.start()

def checkaround(): # 전방이 막혔을때 호출되어 좌우 거리를 측정하는 함수 
    global  R_dist, L_dist
    print("FL :", FL_dist) # 전방 거리가 얼마이길래 멈췄는지 디버깅용
    print("FR :", FR_dist)
    print("F :", F_dist)
    print("---------------------")
    stop() # 일단 멈춤
    LposContDeg(160) # 좌우로 초음파센서 회전
    RposContDeg(-5)
    sleep(1) # 센싱위한 1초 딜레이
    lock.acquire()
    print("checking")
    L_dist = Ldissensor.distance * 100 # 좌우 거리 측정
    R_dist = Rdissensor.distance * 100
    print("L :", L_dist)
    print("R :", R_dist)
    print("---------------------")
    lock.release()
    sleep(1) # 정확히 거리값을 받기위해 1초 딜레이
    LposContDeg(60) # 다시 전방으로 초음파센서 회전
    RposContDeg(100)

def go(): # 150 속도로 직진 (딜레이 없음으로 따로 딜레이 줘야함 => 좌우 회전시 호출해서 사용하기 위함)
    global speed
    speed = 150
    myMotor.setSpeed(speed)
    myMotor.run(Raspi_MotorHAT.BACKWARD)

def back(): # 100 속도로 후진 (마찬가지로 별로 딜레이 필요)
    global speed
    speed = 100
    myMotor.setSpeed(speed)
    myMotor.run(Raspi_MotorHAT.FORWARD)

def stop(): # 정지
    myMotor.setSpeed(speed)
    myMotor.run(Raspi_MotorHAT.RELEASE)

def left(t): # t초동안 150속도로 좌회전
    global speed
    speed = 150
    pwm.setPWM(0, 0, 260)
    go()
    sleep(t) #딜레이를 내장함으로 별도 딜레이 설정 필요 없음
    if t: # t=0 즉 qt로 제어하면 멈추지않고 계속 딜레이 없이 좌회전함
        stop()

def mid(): # 앞바퀴 중앙정렬 ( 5번째 바퀴때문에 오른쪽으로 조금 휘는경향을 보정하기위해 살짝 왼쪽으로 설정함 )
    pwm.setPWM(0, 0, 355)

def right(t): 
    global speed
    speed = 170  # 오른쪽은 바퀴가 하나더 있어 출력이 부족한거 같아서 더 높은 출력으로 회전
    pwm.setPWM(0, 0, 460)
    go()
    sleep(t)
    if t:
        stop()

def avoid(): # 장애물이 있을시 회피하는 함수 (현재 QT로 제어하기위해 사용하지 않는중)
    global stopit
    stop() # 멈춰서
    if stopit: # 이미 6초이상 멈춰있었다 => 장애물에 막혀있으므로 먼저 후진하고 좌우를 살펴보자
        back()
        sleep(1) # 1초간 후진
        stop()
    checkaround() # 좌우 센싱
    if not stopit: # 6초간 멈춘게 아니고 앞에 장애물을 센싱해서 회피기동을 하려는경우 => 장애물과 거리가 있으니 센싱 먼저하고 후진하여 회전할 거리를 확보하자
        back()
        sleep(1)
        stop()
    if L_dist < R_dist: # 오른쪽이 더 뚫려있다면
        right(0.8) #오른쪽으로 돌아서 살짝 직진하고 다시 왼쪽으로 돌아서 정렬
        mid()
        go()
        sleep(1)
        stop()
        left(0.8)
        mid()
    else:
        left(0.8)
        go()
        sleep(1)
        stop()
        right(0.8)
        mid()
    
def autodrive(): # 자율주행 모드
    global stopit, dir, my_y, my_x, target_x, target_y,autostop
    # start setting
    checkfront() # 전방 장애물 센싱 시작
    # caldist()
    mid() # 중앙정렬
    LposContDeg(60) # 초음파 센서 전방 정렬
    RposContDeg(100)
    stop() #3초간 멈춰서 출발할 준비
    sleep(3)
    is_stop() # 멈춰서 진행못하는지 판단 시작
    print("autodrive start") # 시작 알림
    print(my_y,"/",my_x) # 자율주행 시작 좌표
    print(target_y,"/",target_x) # 목적 좌표
    while not(target_x - 10 <= my_x <= target_x + 10 and target_y - 10 <= my_y <= target_y + 10) : # 내 위치가 목표위치 오차범위내에 들어갈때까지 반복
        if autostop: # autodrive모드 종료 버튼을 누르면 종료되도록
            break;
        print("I'm going") # 진행중임을 표시
        if FL_dist <= 35 or FR_dist <= 35 or F_dist<=20 or stopit == 1: # 전방에 장애물이 있거나 6초이상 멈춰있었던 경우
            stop()
            mid()
            if stopit :
                back()
                sleep(1)
                stop()
            checkaround() # 좌우 센싱
            if not stopit:
                back()
                sleep(1)
                stop()
            if L_dist>=50 and R_dist>=50 : # 양쪽모두 충분히 뚫려있다면
                if dir == 0: # 절대 방향으로 +y방향을 보고있던 경우
                    if my_x > target_x: # 목표지점이 내 오른쪽(-x방향)에 있다면
                        right(1.5) # 오른쪽으로 우선돌기 >>> 1.5초 돌게 했지만 시간조절하여 90도 회전하도록 하면 좋음
                        dir = 3 # 오른쪽이라고 방향 변경
                        # ------- 이하 방향에 따라 같은 의미의 코드----------#
                    elif my_x < target_x:
                        left(1.5)
                        dir = 2
                elif dir == 1:
                    if my_x > target_x:
                        left(1.5)
                        dir = 3
                    elif my_x < target_x:
                        right(1.5)
                        dir = 2
                elif dir == 2:
                    if my_y > target_y:
                        right(1.5)
                        dir = 1
                    elif my_y < target_y:
                        left(1.5)
                        dir = 0
                else:
                    if my_y > target_y:
                        left(1.5)
                        dir = 1
                    elif my_y < target_y:
                        right(1.5)
                        dir = 0
            elif L_dist > R_dist: # 좌우 중 하나라도 막혀있는곳이 있을경우 비교적 덜 막힌곳으로 우선 회전
                left(1.5)
                dir = dL[dir]
                print("turn left")
            else:
                right(1.5)
                dir = dR[dir]
                print("turn rigt")
            go()
            sleep(1)
        else: # 전방이 막혀있지 않으면 직진
            mid()
            go()
            sleep(1)
        print("y: ", my_y,"x: ", my_x)
    stop() # 자율주행 종료
    print("finish!!")
    print("y: ", my_y, "x: ", my_x) # 종료된 위치 출력
    timer2.stop() # 쓰레드 종료 (현재 좌표와 누적거리를 갱신하는 쓰레드만 남김)
    timer3.stop()

checkdist() # 누적거리 및 좌표 갱신하는 쓰레드는 자율주행 여부 상관없이 QT제어때도 실행됨

app.exec_() # qt창 닫히면 
GPIO.cleanup() #gpio 할당해제하고 
timer.stop() # 누적거리 계산 쓰레드 타이머 종료