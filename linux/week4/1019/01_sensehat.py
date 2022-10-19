from colorsys import hsv_to_rgb
from email import message
from email.mime.message import MIMEMessage
from time import sleep
from sense_hat import SenseHat 
import time
from signal import pause
# from sense_emu import SenseHat

sense = SenseHat()
x = y = 4

def update_screen():
    global sense
    
    sense.clear()
    sense.set_pixel(x, y, 255, 255, 255)

def clamp(value, min_value=0, max_value=7):
    return min(max_value, max(min_value, value))

def move_dot(event):
    global x, y

    if event.action in ('pressed', 'held'):
        x = clamp(x + {
            'left': -1,
            'right': 1,
            }.get(event.direction, 0))
        y = clamp(y + {
            'up': -1,
            'down': 1,
            }.get(event.direction, 0))

def sense_hat_clear():
    global sense
    sense.clear(255, 255, 255)
    sense.low_light = True
    time.sleep(0.5)
    sense.low_light = False
    sense.clear(0, 0, 0)
    
def print_now_weather():
    ## print temperature
    global sense
    h = sense.get_humidity()
    t = sense.get_temperature()
    p = sense.get_pressure()
    
    h_msg = f"Humidity: {h:.2f} H\n"
    t_msg = f"Temperature: {t:.2f}'C\n"
    p_msg = f"Pressure: {p:.2f}hpa\n"
    message = h_msg + t_msg + p_msg
    
    print(message)
    # sense.show_message(message)
    sleep(1)


def main():
    global sense

    sense_hat_clear()
    sense.low_light = True # low light

    ## show message
    # sense.show_message("HELLO WORLD!")

    ## joystick test
    # update_screen()
    # while True:
    #     for event in sense.stick.get_events():
    #         move_dot(event)
    #         update_screen()

    ## test temp-humid-sensor
    # print_now_weather()

    


main()