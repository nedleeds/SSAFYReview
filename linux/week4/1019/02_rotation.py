from time import sleep
from sense_hat import SenseHat 

sense = SenseHat()

def display_off():
    global sense
    sense.low_light = False
    sense.clear(0, 0, 0)

def main():
    global sense

    display_off()
    sense.low_light = True

    sense.show_message("A")
    sense.set_rotation(90)
    sense.show_message("A")
    sense.set_rotation(180)
    sense.show_message("A")
    sense.set_rotation(270)
    sense.show_message("A")
    sense.set_rotation(0)

    sleep(1)
    display_off()

main()