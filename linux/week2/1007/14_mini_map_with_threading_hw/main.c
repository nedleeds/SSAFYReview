#include <pthread.h>
#include <stdio.h>
#include <ncurses.h>
#include <locale.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#define N 7
char map[N][N + 1] = {
    "#######",
    "#  ^  #",
    "#^##  #",
    "##^^ a#",
    "#^ ^###",
    "# ^  Y#",
    "#######",
};

int ny = 1;
int nx = 1;

int my = 5;
int mx = 1;

int hp = 100;

void* abc()
{
    int direct[4][2] = { -1, 0, 1, 0, 0, 1, 0, -1 };

    while (1)
    {

        int t = (int)rand() % 4;
        int sely = my + direct[t][0];
        int selx = mx + direct[t][1];

        if (map[sely][selx] == '#')
            continue;

        my = sely;
        mx = selx;
        usleep(200 * 1000);
    }

    return 0;
}

void print()
{
    clear();
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            if (y == ny && x == nx)
            {
                printw("ꉡ");
            }
            else if (y == my && x == mx)
            {
                printw("ꎽ");
            }
            else if (map[y][x] == '#')
            {
                printw("▒▒");
            }
            else if (map[y][x] == '^')
            {
                printw("^^");
            }
            else if (map[y][x] == 'Y')
            {
                printw("YY");
            }
            else if (map[y][x] == 'a')
            {
                printw("aa");
            }
            else if (map[y][x] == ' ')
            {
                printw("  ");
            }
        }
        printw("\n");
    }
    printw("HP : %d\n", hp);
    refresh();
}

int main()
{
    srand(time(0));

    setlocale(LC_CTYPE, "ko_KR.utf8");
    initscr();

    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    pthread_t tid;
    pthread_create(&tid, NULL, abc, NULL);

    while (1)
    {
        print();
        int ch = getch();
        if (ch == ERR)
            ch = 0;

        if (ch == KEY_LEFT)
        {
            if (map[ny][nx - 1] != '#')
                nx--;
            if (map[ny][nx] == '^')
                hp -= 10;
        }
        if (ch == KEY_RIGHT)
        {
            if (map[ny][nx + 1] != '#')
                nx++;
            if (map[ny][nx] == '^')
                hp -= 10;
        }
        if (ch == KEY_UP)
        {
            if (map[ny - 1][nx] != '#')
                ny--;
            if (map[ny][nx] == '^')
                hp -= 10;
        }
        if (ch == KEY_DOWN)
        {
            if (map[ny + 1][nx] != '#')
                ny++;
            if (map[ny][nx] == '^')
                hp -= 10;
        }

        if (map[ny][nx] == 'a')
        {
            hp = 100;
            map[ny][nx] = ' ';
        }

        if ((ny == my && nx == mx) || hp == 0)
        {
            print();
            usleep(500 * 1000);
            clear();
            mvprintw(10, 30, "GAME OVER");
            refresh();
            sleep(1);
            break;
        }
        if (map[ny][nx] == 'Y')
        {
            print();
            usleep(500 * 1000);
            clear();
            mvprintw(10, 30, "WIN (%d)", hp);
            refresh();
            sleep(1);
            break;
        }
    }
    pthread_cancel(tid);
    pthread_join(tid, NULL);
    getch();
    endwin();
    return 0;
}