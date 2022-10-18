from gpiozero import AngularServo
from gpiozero import LED, Button, PWMLED
from signal import pause
from time import sleep

# 7-segment GPIO setting
g = LED(14)
f = LED(15)
a = LED(18)
b = LED(23)
e = LED(24)
d = LED(25)
c = LED(8) 
DP = LED(7)
nums = [
    [a, b, c, d, e, f],
    [b, c],
    [a, b, g, e, d],
    [a, b, g, c, d],
    [f, g, b, c],
    [a, f, g, c, d],
    [a, f, g, e, c, d],
    [f, a, b, c],
    [a, b, c, d, e, f, g],
    [a, b, c, d, g, f]
]

allnums = [a,b,c,d,e,f,g,DP]

# Green/Red light bulb GPIO setting
green = LED(26)
red = LED(20)

# Button GPIO setting
btn_left = Button(13)
btn_right = Button(19)

passwd = []
ans = []

def check_servo():
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

def open_door():
    servo = AngularServo(16, min_angle = -90, max_angle = 90)
    
    for a in range(-90, 90, 180):
        servo.angle = a
        sleep(.5)

def close_door():
    servo = AngularServo(16, min_angle = -90, max_angle = 90)

    for a in range(90, -90, -180):
        servo.angle = a
        sleep(.5)
        print(f'curr pulse: {servo.pulse_width}')

def check_7segment():
    def show(n):
        # display number(=duty/10) on the 7 segment module
        for num in nums[8]: num.off()
        for num in nums[n]: num.on()

    # check 7-segment Light
    for i in range(10):
        show(i)
        sleep(1)

def display_num(n):
    for num in nums[8]: num.off()
    for num in nums[n]: num.on()
    green.on()
    red.on()
    sleep(.5)
    for num in nums[8]: num.off()
    green.off()
    red.off()
    sleep(.5)

def get_password():
    from random import random
    passwd = [(int)(random()*123456789) % 2 for _ in range(4)]
    print(f'password: {passwd}')
    for n in passwd:
        display_num(n)

    return passwd

def blinking(color):
    if color == 'red':
        for _ in range(5):
            red.on()
            sleep(.1)
            red.off()
            sleep(.1)
    else:
        for _ in range(5):
            green.on()
            sleep(.1)
            green.off()
            sleep(.1)

def check_ans():
    global ans 
    for a, p in zip(ans, passwd):
        if (a != p):
            blinking('red')
            ans = []
            return 
        else:
            pass

    green.on()
    open_door()
    sleep(1)
    open_door()
    green.off()
    

passwd_idx = 0
def left_pressed():
    # number 0
    global ans, passwd
    ans.append(0)
    print(f'curr passwd: {passwd}')
    print(f'curr ans: {ans}')
    if len(ans) != len(passwd):
        display_num(ans[-1])
    else:
        check_ans()

def right_pressed():
    # number 1
    global ans, passwd
    ans.append(1)
    print(f'curr passwd: {passwd}')
    print(f'curr ans: {ans}')
    if len(ans) != len(passwd):
        display_num(ans[-1])
    else:
        check_ans()

def main():
    # check_7segment()
    # check_servo()
    global passwd

    passwd = get_password()
    
    btn_left.when_pressed = left_pressed
    btn_right.when_pressed = right_pressed

    pause()

main()