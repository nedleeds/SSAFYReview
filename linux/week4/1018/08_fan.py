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

# Button GPIO setting
switch1 = Button(13)
switch2 = Button(19)
switch3 = Button(26)

# motor GPIO setting
motor = PWMLED(21)

# bulb GPIO setting
turn_light = LED(20)

# turn flag - on/off 
turn_flag = 0

# duty for mortor
duty = 0

def show():
    # display number(=duty/10) on the 7 segment module
    print(f'duty: {duty}')

    for num in nums[8]: num.off()
    turn_light.off()
    
    if ((int)(duty / 10) != 0):
        for num in nums[(int)(duty / 10)]: num.on()
        turn_light.on()
    

def check_num():
    # check 7-segment Light
    for i in range(10):
        show(i)
        sleep(1)

def move_fan():
    # move motor -> using PWMLED
    # PWMLED.value should be betwee 0, 1
    global motor, duty

    show()
    force = duty/100
    print(f'force:{force}')
    
    for i in range(100):
        motor.value = force 
        sleep(0.0001)

def turn():
    global duty, turn_flag

    if turn_flag :
        print(f'turn off: {turn_flag}', end = ' ')
        turn_flag = 0
        duty = 0
    else:
        print(f'turn on: {turn_flag:.1f}', end = ' ')
        turn_flag = 1
        duty = 10
        
    move_fan()

def faster():
    global duty
    duty = 90 if duty >= 90 else duty + 10 
    move_fan()

def slower():
    global duty
    duty = 10 if duty <= 10 else duty - 10 
    move_fan()

def main():
    # check_num()
    switch3.when_pressed = turn
    switch1.when_pressed = faster
    switch2.when_pressed = slower

    pause()

main()