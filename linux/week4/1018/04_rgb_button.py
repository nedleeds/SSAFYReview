import os
from gpiozero import PWMLED, Button
from time import sleep
from signal import pause
from random import random

R = PWMLED(17)
G = PWMLED(27)
B = PWMLED(22)

R_Btn = Button(13)
G_Btn = Button(19)
B_Btn = Button(26)

color_list = [1, 1, 1]

def print_color():
    global color
    print(f'R:{color_list[0]:.2f}', end=' ')
    print(f'G:{color_list[1]:.2f}', end=' ')
    print(f'B:{color_list[2]:.2f}')

def turn_on_rgb():
    global color
    R.value = color_list[0]
    G.value = color_list[1]
    B.value = color_list[2]
    sleep(0.1)

def red_on():
    print('Red was pressed')    
    c = color_list[0]
    color_list[0] = 0 if c + 0.1 > 1 else c + 0.1
    print_color()
    turn_on_rgb()

def green_on():
    print('Green was pressed')
    c = color_list[1]
    color_list[1] = 0 if c + 0.1 > 1 else c + 0.1
    print_color()
    turn_on_rgb()

def blue_on():
    print('Blue was pressed')
    c = color_list[2]
    color_list[2] = 0 if c + 0.1 > 1 else c + 0.1
    print_color()
    turn_on_rgb()

def main():
    print('Press the Button - R, G, B')
    
    n = 0
    turn_on_rgb()
    R_Btn.when_pressed = red_on
    G_Btn.when_pressed = green_on
    B_Btn.when_pressed = blue_on

    pause()


main()