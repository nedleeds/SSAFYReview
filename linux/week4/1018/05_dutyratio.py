from gpiozero import LED
from time import sleep
import argparse

led = LED(2)

def get_arguments():
    parser = argparse.ArgumentParser()

    parser.add_argument('--duty_rate',
                        default = '50',
                        type = int,
                        help = '0 <= (int) duty_rate < 100')
    
    args = parser.parse_args()
    return args

def led_on(args):
    print(f'duty_rate: {args.duty_rate:d}%')

    time_on = 1 * (args.duty_rate / 100) 
    time_off = 1 - time_on

    while(True):
        led.on()
        sleep(time_on * 0.002)
        led.off()
        sleep(time_off * 0.002)

def main(args):
    while True:
        led_on(args)


if __name__ == "__main__":
    args = get_arguments()
    main(args)