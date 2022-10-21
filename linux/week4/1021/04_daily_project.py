import board
import digitalio
import time
import adafruit_ssd1306
from PIL import Image, ImageDraw, ImageFont
import RPi.GPIO as GPIO
import numpy as np

# Define the Reset Pin
oled_reset = digitalio.DigitalInOut(board.D24)

# Change these
# to the right size for your display!
WIDTH = 128
HEIGHT = 64  # Change to 64 if needed
BORDER = 5
WHITE = 1
BLACK = 0
image_idx = 0
font_idx = 0

# Use for SPI
spi = board.SPI()
oled_cs = digitalio.DigitalInOut(board.D8)
oled_dc = digitalio.DigitalInOut(board.D25)
oled = adafruit_ssd1306.SSD1306_SPI(WIDTH, HEIGHT, spi, oled_dc, oled_reset, oled_cs)

# GPIO setup
GPIO.setmode(GPIO.BCM)
GPIO.setup(26, GPIO.IN, pull_up_down=GPIO.PUD_UP) #ground 연결 -> PUD_UP
GPIO.setup(21, GPIO.IN, pull_up_down=GPIO.PUD_UP)


def display_image(img_path = './image/jdragon.png', center_cropping = True, resizing = True, dx = 20, dy = -5):
    def clear_display():
        oled.fill(0)
        oled.show()

    def show_image(img):
        # Display image
        oled.image(img)
        oled.show()

    def center_crop(img):
        left   = img.size[0] // 2 - (WIDTH // 2)
        right  = img.size[0] // 2 + (WIDTH // 2)
        upper  = img.size[1] // 2 - (HEIGHT // 2)
        bottom = img.size[1] // 2 + (HEIGHT // 2)

        cropped_img = img.crop((left + dx, upper + dy, right + dx, bottom  + dy))

        return cropped_img

    global image_idx

    images = {
        0: './image/jdragon.png',
        1: './image/jordan.png',
        2: './image/cat.png'
    }
    
    im = Image.open(images[image_idx % 3]).convert('1')

    if (im.size[0] < im.size[1]):
        im = im.rotate(90)

    mode = 'original'
    if center_cropping:
        im = center_crop(im)
        mode = 'center-crop'
    if resizing:
        im = im.resize((WIDTH, HEIGHT))
        mode = 'resize'
    
    print(f'[{mode}]image size: ({im.size[0]}, {im.size[1]})')

    # Get drawing object to draw on image.
    clear_display()
    show_image(im)

    image_idx += 1

def display_font(W=WIDTH, H=HEIGHT, position=(32, 32), words='안녕', font_size = 12):
    from PIL import Image, ImageDraw, ImageFont

    def clear_display():
        oled.fill(0)
        oled.show()

    def show_image(img):
        # Display image
        oled.image(img)
        oled.show()

    black = 0
    white = 1
    
    font = ImageFont.truetype("./font/malgun.ttf",font_size)
    im_font = Image.new('1', (128,64), black)
    draw = ImageDraw.Draw(im_font)

    draw.text( position, f'''{words}''', font=font, fill=white)

    clear_display()
    im_font = im_font.transpose(Image.FLIP_LEFT_RIGHT)
    im_font = im_font.rotate(90)
    show_image(im_font)

def display_datetime():
    from datetime import datetime
    now = datetime.now()
    time_str = now.strftime('%I:%M:%S')
    display_font(position=(29, 20), words=f'{time_str}', font_size = 20)

def mode_switch(channel):
    # 빨간 버튼 누르면 모드 변경 -> mode_index 바꾸기
    global mode_idx
    print(f'{channel} has been pressed')
    idx = mode_idx % 3

    if idx == 0:
        display_datetime()
        flag['date'] = 1
        flag['image'] = 0

    elif idx == 1:
        display_image()
        flag['image'] = 1
        flag['date'] = 0

    mode_idx += 1 

def screen_switch(channel):
    global image_idx, font_idx

    print(f'{channel} has been pressed')

    if flag['date']:
        print(f'font idx {font_idx}')
        if font_idx % 2 == 0:
            display_font(words = "전투력 측정 중...")
        else:
            display_datetime()
        font_idx += 1

    if flag['image']:
        image_idx += 1
    


# interrupt 선언
# GPIO.RISING  : LOW  -> HIGH 되는 순간
# GPIO.FALLING : HGIHG -> LOW 되는 순간
GPIO.add_event_detect(21, GPIO.RISING, callback=mode_switch   , bouncetime=1000) #red
GPIO.add_event_detect(26, GPIO.RISING, callback=screen_switch, bouncetime=1000) #green

# 메인 루프
try:
    
    mode_idx = 0
    flag = {'date':0, 'image': 0}
    while 1:
        print(".")
        time.sleep(0.1)
finally:
    GPIO.cleanup()