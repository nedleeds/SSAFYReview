from gpiozero import Button
from signal import pause

flag = 0

def say_hello():
	print("Hello")

def say_goodbye():
	print("GoodBye")

def go():
	global flag
	if flag == 0:
		flag = 1
		print("YO")
	else:
		flag = 0
		print("Check")

def main():
	button = Button(2)
	button.when_pressed = go

	pause()	


main()


