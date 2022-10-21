# # gpio-interrupt-test.py
# # GPIO12에 입력이 들어오면 문장을 출력한다.
# # 라이브러리 불러오기
# import RPi.GPIO as GPIO
# import time
# # 스위치 눌렸을 때 콜백함수
# def switchPressed(channel):
#     print('channel %s pressed!!'%channel)

# # GPIO setup
# GPIO.setmode(GPIO.BCM)
# GPIO.setup(12, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
# # interrupt 선언
# GPIO.add_event_detect(12, GPIO.RISING, callback=switchPressed)
# # 메인 루프
# try:
#     while 1:
#         print(".")
#         time.sleep(0.1)
# finally:
#     GPIO.cleanup()

import RPi.GPIO as GPIO
import time

def switchPressed(channel):
    print(f'channel {channel} pressed')

# def GPIO_SETTING():
GPIO.setmode(GPIO.BCM)
GPIO.setup(12, GPIO.IN, pull_up_down = GPIO.PUD_UP) # 스위치 안눌렸을 때 on, 눌렸을 때 off
# GPIO.setup(21, GPIO.OUT)
GPIO.add_event_detect(12, GPIO.RISING, callback = switchPressed)

try:
    # GPIO_SETTING()

    while 1:
        print(".")
        time.sleep(0.1)

finally:
    GPIO.cleanup()