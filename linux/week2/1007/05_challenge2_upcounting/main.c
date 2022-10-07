#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	initscr();

	for (int i=0; i<1000; i++){
		printw("%.02f", i/100.0);
		refresh();
		usleep(10*1000);
		clear();
	}

	printw("FINISH");
	getch();
	
	endwin();	
	return 0;
}
