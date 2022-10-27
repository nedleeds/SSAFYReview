#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int fd = open("/dev/nobrand", O_RDWR);
    if (fd < 0)
    {
        printf("ERROR\n");
        close(fd);
        exit(1);
    }

    // read char
    // char buf[100];
    // read(fd, buf, 100);
    // printf("%s\n", buf);

    // wrtie 7 char
    write(fd, "KFC JJANG\n", 20);

    char buf[100];
    read(fd, buf, 100);
    printf("%s\n", buf);

    close(fd);
    return 0;
}
