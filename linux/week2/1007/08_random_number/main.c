#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main(){
	initscr();

	// srand(시간값): 시간 별 랜덤 seed 설정
	srand(time(NULL));

	while(1){
		clear();
		for (int i=0; i<10; i++){
			printw("%d ", rand() % 10);
		}
		refresh();
		sleep(1);
	}

	getch();
	endwin();
	return 0;
}
