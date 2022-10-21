import board
import digitalio
import numpy as np
import adafruit_ssd1306
from PIL import Image, ImageDraw, ImageFont

# Define the Reset Pin
oled_reset = digitalio.DigitalInOut(board.D24)

# Change these
# to the right size for your display!
WIDTH = 128
HEIGHT = 64  # Change to 64 if needed
BORDER = 5
WHITE = 1
BLACK = 0

# Use for SPI
spi = board.SPI()
oled_cs = digitalio.DigitalInOut(board.D8)
oled_dc = digitalio.DigitalInOut(board.D25)
oled = adafruit_ssd1306.SSD1306_SPI(WIDTH, HEIGHT, spi, oled_dc, oled_reset, oled_cs)


def display_image(img_path = './image/cat.png', center_cropping = False, resizing = False, dx=0, dy=0):
    def clear_display():
        oled.fill(0)
        oled.show()

    def show_image(img):
        # Display image
        oled.image(img)
        oled.show()

    def center_crop(img):

        # frac = 0.90
        # left = img.size[0]*((1-frac)/2)
        # upper = img.size[1]*((1-frac)/2)
        # right = img.size[0]-((1-frac)/2)*img.size[0]
        # bottom = img.size[1]-((1-frac)/2)*img.size[1]

        left   = img.size[0] // 2 - (WIDTH // 2)
        right  = img.size[0] // 2 + (WIDTH // 2)
        upper  = img.size[1] // 2 - (HEIGHT // 2)
        bottom = img.size[1] // 2 + (HEIGHT // 2)

        cropped_img = img.crop((left + dx, upper + dy, right + dx, bottom  + dy))

        return cropped_img
    
    im = Image.open(img_path).convert('1')

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


def display_font(W=WIDTH, H=HEIGHT, position=(32, 32), words='안녕', font_size = 15):
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
    show_image(im_font)

def display_datetime():
    from datetime import datetime

    now = datetime.now()
    time_str = now.strftime('%I:%M:%S')
    display_font(position=(29, 20), words=f'{time_str}', font_size = 20)



def main():
    # oled.fill(0)
    # oled.show()
    # display_font(position=(24,20), words="하이하이", font_size=20)
    display_image('./image/jdragon.png', True, True, dx = 20, dy = -5)
    # display_datetime()


main()