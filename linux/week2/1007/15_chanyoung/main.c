#include<stdio.h>

#include<ncurses.h>

#include<locale.h>

#include<unistd.h>

#include<stdlib.h>

#include<time.h>

#define N 10

char map[N][N+1] ={
        "##########",
        "#  M     #",
        "#^###  ^ #",
        "#       a#",
        "#  ^ ^####",
        "#       Y#",
        "#        #",
        "#        #",
        "#        #",
        "##########",
};

int ny =1;
int nx =1;
int hp=100;

int my =N-3;
int mx =2;

int nyy,nxx;
int myy,mxx;

int yy[4] = {0,0,1,-1};
int xx[4] = {1,-1,0,0};

void print()
{
        clear();
        for(int y=0; y<N; y++)
        {
                for(int x=0; x<N;x++)
                {
                        if(y==ny && x==nx)
                        {
                                printw("@");
                        }
                        else if(y==my && x==mx)
                        {
                                printw("T");
                        }
                        //else if(map[y][x]=='#')
                        //{
                                //printw("▦");
                        //}
                        else printw("%c",map[y][x]);
                }
                printw("\n");
        }
        mvprintw(15,20,"HP:%d",hp);
        refresh();
}

void gameover()
{
        usleep(500000);
        clear();
        mvprintw(25,40,"GAME OVER");
        refresh();
        sleep(1);
}

void win()
{
        usleep(500000);
        clear();
        mvprintw(25,40,"WIN (%d) ",hp);
        refresh();
        sleep(1);
}

int main()
{
        setlocale(LC_CTYPE,"ko_KR.utf8");
        initscr();

    curs_set(0);
    srand(time(NULL));

    nodelay(stdscr,TRUE);
    keypad(stdscr,TRUE);
    while(1)
    {
            print();

            nyy = ny;
            nxx = nx;

            myy = my;
            mxx = mx;

            usleep(200000);
            my += yy[rand()%4];
            mx += xx[rand()%4];

            if(map[my][mx] =='#'||map[my][mx]=='Y')
            {
                    my = myy;
                    mx = mxx;
            }
            int ch = getch();
            if(ch == KEY_LEFT)
            {
                    if(map[ny][nx-1]!='#') nx--;
            }
            if(ch==KEY_RIGHT)
            {
                    if(map[ny][nx+1]!='#') nx++;
            }
            if(ch==KEY_UP)
            {
                    if(map[ny-1][nx]!='#') ny--;
            }
            if(ch==KEY_DOWN)
            {
                    if(map[ny+1][nx]!='#') ny++;
            }
            if(map[ny][nx]=='M')
            {
                    gameover();
                    break;
            }
            if(map[ny][nx]=='Y')
            {
                    win();
                    break;
            }
            if(map[ny][nx]=='^'&&(nx!=nxx||ny!=nyy))hp-=10;
            if(map[ny][nx]=='a')
            {
                    map[ny][nx]=' ';
                    hp+=10;
            }
            if(ny==my && nx==mx)
            {
                    gameover();
                    break;
            }
            if(hp<=0)
            {
                    gameover();
                    break;
            }

    }

    getch();
    endwin();

    return 0;
}


