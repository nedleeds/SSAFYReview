from gpiozero import PWMLED
from time import sleep
import os

led = PWMLED(2)
led.value = 0
sleep(1)

while True:
    n = int(input("Put the number(0-exit): "))
    print(f"Light: {led.value}")
    if (n == 0) :
        sleep(1)
        break
    elif (n == 1):
        led.value += 0.1
        sleep(1)
    elif (n == 2):
        led.value -= 0.1
        sleep(1)

led.value = 0
sleep(1)
os.system('clear')