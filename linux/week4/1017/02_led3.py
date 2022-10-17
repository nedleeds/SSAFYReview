from gpiozero import LED
from time import sleep

led_set = [LED(17), LED(22), LED(26)]
mode = [0 for _ in range(len(led_set))]

def led_toggle(n):
	if mode[n] == 0:
		led_set[n].on()
	else:
		led_set[n].off()

	mode[n] = not mode[n]

while True:
	n = int(input("input >>> "))
	led_toggle(n-1)




