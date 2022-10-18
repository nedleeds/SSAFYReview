import os
from gpiozero import PWMLED
from time import sleep
from random import random

R = PWMLED(17)
G = PWMLED(27)
B = PWMLED(22)

while True:
    red = random()
    green = random()
    blue = random()
    print(f'R:{red:.2f} G:{green:.2f} B:{blue:.2f}')
    R.value = red
    G.value = green
    B.value = blue
    sleep(0.1)

os.system('clear')