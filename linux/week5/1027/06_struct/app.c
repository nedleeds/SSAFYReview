#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char buf[30] = "THIS IS APP MEMORY";
struct Node {
    char n;
    char buf[100];
};

int main()
{
    int fd = open("/dev/nobrand", O_RDWR);
    if (fd < 0)
    {
        printf("ERROR\n");
        close(fd);
        exit(1);
    }

    int n;
    struct Node t = {1, "THIS IS APP MEMORY"};
    while(1)
    {
        printf("ioctl num >> ");
        scanf("%d", &n);
        if (n == 3)
        {
            ioctl(fd, _IO(0, 3), buf);
        }
        if (n == 4)
        {
            ioctl(fd, _IO(0, 4), buf);
            printf("%s\n", buf);
        }
        if (n == 5)
        {
            ioctl(fd, _IO(0, 5), &t);
        }
    }

    close(fd);
    return 0;
}
