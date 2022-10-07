#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main(){
	initscr();

	// srand(시간값): 시간 별 랜덤 seed 설정
	srand(time(NULL));

	int mx = 0, my = 0;
	getmaxyx(stdscr, mx, my);
	printf("terminal size(row x col): ");
	printf("%d x %d\n", mx, my);

	while(1){
		int r = rand()%39;
		int c = rand()%79;

		for (int row = 0; row<20; row++){
			mvprintw(r+row,c,"#");
			usleep(10*1000);
			refresh();
		}
		
		refresh();
		clear();
		usleep(10*1000);
	}

	getch();
	endwin();
	return 0;
}
