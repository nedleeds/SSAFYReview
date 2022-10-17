from gpiozero import Button, LED
from signal import pause
from time import sleep

flag = []
green = LED(10)
yello = LED(9)
red = LED(11)

def toggle():
	print('btn1 pressed')
	n = 3
	while(n):
		green.on()
		sleep(1)
		green.off()
		yello.on()
		sleep(1)
		yello.off()
		n -= 1

def simultaneous():
	print('btn2 pressed')
	n = 3
	while(n):
		green.on()
		yello.on()
		sleep(1)
		green.off()
		yello.off()
		sleep(1)
		n -= 1

def main():

	btn1 = Button(2)
	btn2 = Button(3)

	while(1):

		btn1.when_pressed = toggle
		btn2.when_pressed = simultaneous

		pause()

main()
