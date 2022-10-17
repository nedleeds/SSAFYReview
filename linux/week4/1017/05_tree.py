from gpiozero import Button, LED
from signal import pause
from time import sleep

greens = [LED(17), LED(22), LED(9)]
reds = [LED(27), LED(10)]
flag = 0

def light(led_list, mode=0):
	for led in led_list:
		print(led)
		if(mode):
			led.on()
		else:
			led.off()

def christmas_tree():
	global flag 

	if (flag):
		light(greens, 1)
		light(reds, 0)
		flag = 0
	else:
		light(greens, 0)
		light(reds, 1)
		flag = 1

def main():
	btn1 = Button(2)

	btn1.when_pressed = christmas_tree
	pause()



main()
