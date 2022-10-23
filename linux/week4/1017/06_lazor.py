from gpiozero import LED, Button
from time import sleep
from signal import pause

lazer = LED(4)
flag = 0

def lazor_turn():
	global flag
	
	if(flag==0):
		lazer.on()
		flag = 1
	else:
		lazer.off()
		flag = 0

while True:
	btn = Button(2)
	
	btn.when_pressed = lazor_turn	
	pause()

