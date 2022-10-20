import smbus #for I2C
from time import sleep 
from bmp280 import BMP280

DEVICE_BUS = 1
DEVICE_ADDR = 0x76 #I2C
BUS = smbus.SMBus(DEVICE_BUS)

while True:
    a = BUS.read_byte_data(DEVICE_ADDR, 0xFB)
    b = BUS.read_byte_data(DEVICE_ADDR, 0xFA)
    c = BUS.read_byte_data(DEVICE_ADDR, 0xFC)
    
    print(a, b, c)
    result = (a << 12) | (b << 4) | ((c & 0XF0) >> 4)
    print(result)

    sleep(0.5)