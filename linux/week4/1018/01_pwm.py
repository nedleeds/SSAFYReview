<<<<<<< Updated upstream
from gpiozero import PWMLED
from time import sleep

led = PWMLED(2)

while True:
    led.value = 0
    sleep(1)
    led.value = 0.5
    sleep(1)
    led.value = 1
    sleep(1)
=======
from gpiozero import PWMLED
from time import sleep

led = PWMLED(2)

while True:
    led.value = 0
    sleep(1)
    led.value = 0.5
    sleep(1)
    led.value = 1
    sleep(1)
>>>>>>> Stashed changes
