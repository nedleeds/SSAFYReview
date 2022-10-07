#include <stdio.h>
#include <ncurses.h>
#include <locale.h>

char map[5][6] = {
	"#####",
	"#   #",
	"#   #",
	"#   #",
	"#####"
};

int nr = 1;
int nc = 1;

void print(){
	clear();
	for (int r = 0; r < 5; r ++){
		for (int c = 0; c < 5; c++){
			if (r==nr && c == nc){
				printw("@");
			}
			else{
				printw("%c", map[r][c]);
			}
		}
		printw("\n");
	}
	refresh();
}


int main(){

	setlocale(LC_CTYPE, "ko_KR.utf8");
	initscr();
	curs_set(0);

	keypad(stdscr, TRUE);
	while(1){
		print();
		int ch = getch();
		clear();

		if (ch == KEY_LEFT){
			nc--;
		}
		else if (ch == KEY_RIGHT){
			nc++;
		}
		else if (ch == KEY_UP){
			nr--;
		}
		else if (ch == KEY_DOWN){
			nr++;
		}
	}

	getch();
	endwin();
	return 0;
}
