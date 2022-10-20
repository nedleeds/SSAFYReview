import smbus #for I2C
from time import sleep 
from bmp280 import BMP280

DEVICE_BUS = 1
DEVICE_ADDR = 0x76 #I2C
BUS = smbus.SMBus(DEVICE_BUS)
bmp280 = BMP280(i2c_dev=BUS)

while True:
    temperature = bmp280.get_temperature()
    pressure = bmp280.get_pressure()
    
    print(f'{temperature:05.2f}\'C {pressure:05.2f}hPa')

    sleep(0.5)
    