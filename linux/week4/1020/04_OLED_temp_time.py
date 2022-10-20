#!/usr/bin/python
# -*- coding:utf-8 -*-

import sys
import os
picdir = os.path.join(os.path.dirname(os.path.dirname(os.path.realpath(__file__))), 'pic')
libdir = os.path.join(os.path.dirname(os.path.dirname(os.path.realpath(__file__))), 'lib')
if os.path.exists(libdir):
    sys.path.append(libdir)

import logging    
import time
import traceback
from waveshare_OLED import OLED_0in96
from PIL import Image,ImageDraw,ImageFont
logging.basicConfig(level=logging.DEBUG)

######### temperature ##########
import smbus #for I2C
from time import sleep 
from bmp280 import BMP280

DEVICE_BUS = 1
DEVICE_ADDR = 0x76 #I2C
BUS = smbus.SMBus(DEVICE_BUS)
bmp280 = BMP280(i2c_dev=BUS)

def get_temperature():
    temperature = bmp280.get_temperature()
    pressure = bmp280.get_pressure()
    
    # print(f'{temperature:05.2f}\'C {pressure:05.2f}hPa')

    return temperature, pressure
###############################


######### time ##########
import datetime
def get_time():
    today = datetime.datetime.today()
    return f"{today.hour}:{today.minute}"
    
#########################

try:
    disp = OLED_0in96.OLED_0in96()

    logging.info("\r 0.96inch OLED ")
    # Initialize library.
    disp.Init()
    # Clear display.
    logging.info("clear display")
    disp.clear()

    # Create blank image for drawing.
    font_big = ImageFont.truetype(os.path.join(picdir, 'Font.ttc'), 30)
    font_small = ImageFont.truetype(os.path.join(picdir, 'Font.ttc'), 20)
    font_semi_tiny = ImageFont.truetype(os.path.join(picdir, 'Font.ttc'), 18)
    font_tiny = ImageFont.truetype(os.path.join(picdir, 'Font.ttc'), 12)


    logging.info ("***draw text")
    while(True):
        image1 = Image.new('1', (disp.width, disp.height), "WHITE")
        draw = ImageDraw.Draw(image1)   
        
        # disp.clear()
        # celcious
        t, h = get_temperature()
        t_front = int(t)
        t_back = int((t - t_front)*10)
        dot = "o"
        celcious = 'C'
        
        draw.text((4,1), f'{t_front:d}.', font = font_big, fill = 0)
        draw.text((45,11), f'{t_back:d}', font = font_small, fill = 0)
        draw.text((53,0), f'{dot}', font = font_tiny, fill = 0)
        draw.text((61,3), f'{celcious}', font = font_semi_tiny, fill = 0)
        print(f'{t_front}.{t_back}\'C')

        # time
        curr_time = get_time()
        draw.text((4,32), f'{curr_time}', font = font_big, fill = 0)

        image1 = image1.rotate(0) 
        disp.ShowImage(disp.getbuffer(image1))

        time.sleep(5)
    
    
except IOError as e:
    logging.info(e)
    
except KeyboardInterrupt:    
    logging.info("ctrl + c:")
    OLED_0in96.config.module_exit()
    exit()