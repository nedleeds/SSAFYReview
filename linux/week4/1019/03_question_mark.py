import numpy as np
from time import sleep
from sense_hat import SenseHat 

sense = SenseHat()

def display_off():
    global sense
    sense.low_light = False
    sense.clear(0, 0, 0)

def get_question_mark():
    O = [0, 0, 0]
    X = [150, 0, 150]

    mark = [
        O, O, O, X, X, O, O, O,
        O, O, X, O, O, X, O, O,
        O, O, X, O, O, X, O, O,
        O, O, O, O, X, O, O, O,
        O, O, O, X, O, O, O, O,
        O, O, O, X, O, O, O, O,
        O, O, O, O, O, O, O, O,
        O, O, O, X, O, O, O, O,
    ]

    return mark

def main():
    global sense

    sense.low_light = True


    sense.set_pixels(get_question_mark())
        
    sleep(3)
    display_off()

main()