import os
from gpiozero import LED
from time import sleep

light = LED(17)

def turn_on(t):
    print("Time :", t, end='\r')
    light.on()
    sleep(t)
    light.off()
    sleep(t)
    

for i in range(100, 1, -10):
    j = float(i/100)
    if i <= 10:
        n = 0
        while(n < 100):
            turn_on(j-(n/1000))
            n+=1
    else:
        turn_on(j)
    os.system('clear')
  
