#include <ncurses.h>
#include <unistd.h>


int main(){
	initscr();

	for (int i=3; i>=0; i--){
		printw("[%d]", i);
		refresh();
		sleep(1);
		clear();
	}
	
	endwin();
	return 0;
}
