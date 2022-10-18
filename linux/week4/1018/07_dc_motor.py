from gpiozero import LED, PWMLED
from time import sleep

def motor_LED():
    motor = LED(6)
    for i in range(20):
        motor.on()
        sleep(1)
        motor.off()
        sleep(1)
    
def motor_PWMLED():
    motor = PWMLED(6)
    for i in range(20):
        motor.value = 0
        sleep(1)
        motor.value = 0.1
        sleep(1)
        motor.value = 0.5
        sleep(1)

def main():
    while(1):
        opt = input('motor with LED/PWMLED(0/1): ')
        if opt == '1':
            print('LED mode')
            motor_LED()
        else:
            print('PWDLED mode')
            motor_PWMLED() 


main()