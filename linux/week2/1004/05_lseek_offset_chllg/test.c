#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int fd = open("./test.txt", O_RDONLY, 0);
    if (fd < 0)
    {
        printf("FILE OPEN ERROR\n");
        exit(1);
    }

    char buf[11] = {0};
    lseek(fd, 0, SEEK_SET);
    read(fd, buf, 5);
    printf("%s\n", buf);

    lseek(fd, -6, SEEK_END);
    read(fd, buf, 5);
    printf("%s\n", buf);

    memset(buf, 0, 11);
    lseek(fd, 0, SEEK_SET);
    while (1)
    {
        read(fd, buf, 3);
        if (strcmp(buf, "GHI"))
            continue;

        lseek(fd, 5, SEEK_CUR);
        read(fd, buf, 3);
        printf("%s\n", buf);
        break;
    }

    close(fd);
    return 0;
}
