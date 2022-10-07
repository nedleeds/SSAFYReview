#include <ncurses.h>
#include <unistd.h>
#include <string.h>

int main(){
	initscr();

	for(char c='A'; c<='Z'; c++){
		printw("%c", c);
		usleep(100*1000);
		refresh();
	}

	endwin();
	return 0;

}
