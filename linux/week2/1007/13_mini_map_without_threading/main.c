#include <stdbool.h>
#include <stdio.h>
#include <ncurses.h>
#include <locale.h>
#include <unistd.h>
#include <stdlib.h>
#define N 10

char map[N][N + 1] = {
	"##########",
	"#  M ^^^^#",
	"#^##  ^^ #",
	"#  ^ ^ ^ #",
	"#^  ##   #",
	"#  ^ Y   #",
	"##########"
};

int nr = 1;
int nc = 1;
int hp = 100;
bool isFinish;

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
	printw("HP : %d\n", hp);
	refresh();
}

void* checkPosition(){
	if (map[nr][nc] == '#'){
		printw("#");	
	}
	else if (map[nr][nc] == 'M' || hp == 0){
		usleep(50*1000);
		clear();
		int mx = 0, my = 0;
		getmaxyx(stdscr, mx, my);
		move(mx/2, my/2-4);
		printw("GAME OVER");
		isFinish = true;
	}
	else if (map[nr][nc] == 'Y'){
		usleep(50*1000);
		clear();
		int mx = 0, my = 0;
		getmaxyx(stdscr, mx, my);
		move(mx/2, my/2);
		printw("WIN");
		isFinish = true;
	}
	else if (map[nr][nc] =='^'){
		map[nr][nc] = ' ';
	}

	if (hp<=0){
		usleep(50*1000);
		clear();
		int mx = 0, my = 0;
		getmaxyx(stdscr, mx, my);
		move(mx/2, my/2);
		printw("DIE");
		isFinish = true;
	}
}

bool checkNext(int row, int col){
	if (map[row][col] == '#')
		return false;
	else if (map[row][col] == '^'){
		hp-=10;
		hp = (hp<0) ? 0 : hp;
	}
}

int main(){
	// sudo apt install language-pack-ko
	setlocale(LC_CTYPE, "ko_KR.utf8");

	initscr();
	curs_set(0);
	
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);

	while(1){
		print();
		checkPosition();
		int ch = getch();
		if (ch == ERR) ch =0;
		clear();


		if (ch == KEY_LEFT){
			if (checkNext(nr, nc-1))
				nc--;
		}
		else if (ch == KEY_RIGHT){
			if (checkNext(nr, nc+1))
				nc++;
		}
		else if (ch == KEY_UP){
			if (checkNext(nr - 1, nc))
				nr--;
		}
		else if (ch == KEY_DOWN){
			if (checkNext(nr + 1, nc))
				nr++;
		}
		if (isFinish)
			break;
	}

	getch();
	endwin();
	return 0;
}
