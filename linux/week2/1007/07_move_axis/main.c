#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	initscr();

	while(1){
		//clear();
		int r = rand()%10;
		int c = rand()%50;
		move(r, c);
		//printw("[%d, %d]\n", r, c);
		printw("*\n");
		refresh();
		usleep(100*1000);
	}

	endwin();
	return 0;
}
