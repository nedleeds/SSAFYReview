import time
from Raspi_MotorHAT import Raspi_MotorHAT

mh = Raspi_MotorHAT(0x6F) # motor-HAT i2c주소
myMotor = mh.getMotor(2)
myMotor.setSpeed(500)
servo = mh._pwm
servo.setPWMFreq(50)
servoMin = 0
servoMin = 400

'''
Raspi_MotorHAT.FORWARD 전진
Raspi_MotorHAT.BACKWARD 후진
Raspi_MotorHAT.RELEASE 정지
'''

def speedUP():
    speed = myMotor.getSpeed() * 1.1;
    myMotor.setSpeed(speed)

def speedDown():
    speed = myMotor.getSpeed() * 0.9;
    myMotor.setSpeed(speed)

def go():
    myMotor.run(Raspi_MotorHAT.FORWARD)

def stop():
    myMotor.run(Raspi_MotorHAT.RELEASE)

def back():
    myMotor.run(Raspi_MotorHAT.BACKWARD)

def left():
    servo.setPWM(0, 0, 0)
    time.sleep(1)
    servo.setPWM(0, 0, 200)
    time.sleep(1)

def right():
    servo.setPWM(0, 0, 0)
    time.sleep(1)
    servo.setPWM(0, 0, 0)
    time.sleep(1)

# left()
right()