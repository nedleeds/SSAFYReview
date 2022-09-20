#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	while(1){
		int idx=0;
		char cmds[40];
		printf("SSAFY > ");
		scanf("%s", cmds);
	
		printf("input: %s\n", cmds);
	
		if (strcmp(cmds,"date")==0){
			system("date");
		}else if (strcmp(cmds,"uptime")==0){
			system("uptime");
		}else if (strcmp(cmds,"ls")==0){
			system("ls -al");
		}else if (strcmp(cmds,"log")==0){
			system("dmesg");
		}else if (strcmp(cmds, "exit")==0){
			system("exit");
			return 0;
		}else{
			printf("ERROR\n");
		}
	}
	return 0;
}
