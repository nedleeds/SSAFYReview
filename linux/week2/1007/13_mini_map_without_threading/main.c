#include <stdio.h>
#include <ncurses.h>
#include <locale.h>
#include <unistd.h>
#define N 7

char map[N][N + 1] = {
	"#######",
	"#  M  #",
	"# ##  #",
	"#     #",
	"#   ###",
	"#    Y#",
	"#######"
};

int nr = 1;
int nc = 1;

void print(){
	clear();
	for (int r = 0; r < N; r ++){
		for (int c = 0; c < N; c++){
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

void* checkPosition(){
	if (map[nr][nc] == '#'){
		printw("#");	
	}
	else if (map[nr][nc] == 'M'){
		usleep(50*1000);
		clear();
		int mx = 0, my = 0;
		getmaxyx(stdscr, mx, my);
		move(mx/2, my/2);
		printw("GAME OVER");
	}
	else if (map[nr][nc] == 'Y'){
		usleep(50*1000);
		clear();
		int mx = 0, my = 0;
		getmaxyx(stdscr, mx, my);
		move(mx/2, my/2);
		printw("WIN");
	}
}

int main(){
	// sudo apt install language-pack-ko
	setlocale(LC_CTYPE, "ko_KR.utf8");

	initscr();
	curs_set(0);

	keypad(stdscr, TRUE);
	while(1){
		print();
		checkPosition();
		int ch = getch();
		clear();


		if (ch == KEY_LEFT){
            if (map[nr][nc - 1] != '#')
            {
                nc--;
            }
		}
		else if (ch == KEY_RIGHT){
			if (map[nr][nc + 1] != '#')
				nc++;
		}
		else if (ch == KEY_UP){
			if (map[nr - 1][nc] != '#')
				nr--;
		}
		else if (ch == KEY_DOWN){
			if (map[nr + 1][nc] != '#')
				nr++;
		}
	}

	getch();
	endwin();
	return 0;
}
