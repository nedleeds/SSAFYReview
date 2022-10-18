from time import sleep
from signal import pause
from gpiozero import LED, Button

led = LED(2)
Btn_1 = Button(13)
Btn_2 = Button(19)
duty_rate = 10
STEP = 30

def led_on():
    print(f'duty_rate: {duty_rate:d}%')

    time_on = 1 * (duty_rate / 100) 
    time_off = 1 - time_on
    
    for i in range(100):
        led.on()
        sleep(time_on * 0.002)
        led.off()
        sleep(time_off * 0.002)

def brighter():
    global duty_rate


    duty_rate = 90 if duty_rate >= 100-STEP else duty_rate + STEP
    led_on()

def darker():
    global duty_rate

    duty_rate = 10 if duty_rate <= STEP else duty_rate - STEP
    led_on()

def main():
    led_on()
    Btn_1.when_pressed = brighter
    Btn_2.when_pressed = darker
    pause()


main()