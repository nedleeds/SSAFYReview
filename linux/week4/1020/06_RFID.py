from gpiozero import LED, AngularServo
from mfrc522 import SimpleMFRC522
from time import sleep

green = LED(20)
red = LED(4)
servo = AngularServo(19, min_angle = -90, max_angle = 90)
near_flag = 0
pass_flag = 0

def supersonic():
    from gpiozero import DistanceSensor
    sensor = DistanceSensor(23, 24)
    return int(sensor.distance*100)
    
def is_near():    
    global near_flag
    if supersonic() <= 5:
        green.on()
        return True
    else:
        green.off()
        return False

def servo_rotate(mode = 'open'):
    if mode == 'open':
        for a in range(-90, 90, 180):
            servo.angle = a
            sleep(.5)
    else:
        for a in range(90, -90, -180):
            servo.angle = a
            sleep(.5)

def card_check():
    global pass_flag

    id = SimpleMFRC522().read()
    if id:
        pass_flag = 1
    else:
        pass_flag = 0

    return pass_flag

def main():
    while True:
        near = is_near()
        card = card_check()
        if near and card:
            servo_rotate('open')
            print('Hello, sir')
        elif not near:
            servo_rotate('close')
            for _ in range(5):
                red.on()
                sleep(0.1)
                red.off()
            print('You just put the card without you')

main()        