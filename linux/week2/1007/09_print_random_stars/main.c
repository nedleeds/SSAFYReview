#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main(){
	initscr();

	// srand(시간값): 시간 별 랜덤 seed 설정
	srand(time(NULL));

	while(1){
		int r = rand()%79;
		int c = rand()%39;
		move(r, c);
		printw("*");
		
		refresh();
		usleep(10*1000);
	}

	getch();
	endwin();
	return 0;
}
