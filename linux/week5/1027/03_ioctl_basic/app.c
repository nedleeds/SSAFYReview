#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
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

    ioctl(fd, _IO(0, 3), 111);
    ioctl(fd, _IO(0, 4), 222);
    ioctl(fd, _IO(0, 5), 333);

    close(fd);
    return 0;
}
