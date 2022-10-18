from gpiozero import AngularServo
from time import sleep

servo = AngularServo(16, min_angle = -90, max_angle = 90)

while(1):
    for a in range(-90, 90, 180):
        servo.angle = a
        sleep(.5)
        print(f'curr pulse: {servo.pulse_width}')

    for a in range(90, -90, -180):
        servo.angle = a
        sleep(.5)
        print(f'curr pulse: {servo.pulse_width}')
