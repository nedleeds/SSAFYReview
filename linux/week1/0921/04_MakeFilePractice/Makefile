MSG1 = "One"
MSG2 = "Two"
NAME = "OH"
SIMPLE := $(NAME)
RECUL = $(NAME)
NAME += "GOOD"
NAME += "KFC"

GOOD += "BTS"
GOOD += "ABC"
BTS = $(GOOD)
HOT := $(GOOD)

write:
	@echo "[$@] 명령어 수행 중.."
	@dd if=/dev/zero of=./dummy.dat bs=10M count=1
	@echo "[$@] 명령어 수행 완료"

read:
	@echo "[$@] 명령어 수행 중.."
	@dd if=./dummy.dat of=/dev/null bs=1024
	@echo "[$@] 명령어 수행 완료"

clean:
	@rm dummy.dat
	@echo "[$@] 완료"

TARGET:
	@echo "THIS IS [$@]"

A1 :
	mkdir hi
	cd hi
	ls

B1 :
	cd ..
	rmdir hi
	ls 

who :
	@echo $(SIMPLE)
	@echo $(RECUL)
HI: one two
	@echo "Hi"
HELLO:
	@echo ${asdasd}
one: HELLO
	@echo $(MSG1)
two:
	@echo ${MSG2}
A:
	@echo " "" "" ""#"
	@echo " "" ""#""#"
	@echo " ""#""#""#"
	@echo "#"" "" "" ""#"

B:
	@echo "#""#"" "
	@echo "#"" ""#"
	@echo "#""#""#"
	@echo "#"" ""#"
	@echo "#""#"" "
All: A B
