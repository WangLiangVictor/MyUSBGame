#include "main_include.h"

int open_port(int fd, int comport)
{
    long vdisable = 0;

    if(comport == 1)
    {
        fd = open("/dev/ttyS0", O_RDWR | O_NOCTTY | O_NDELAY);
        if(-1 == fd)
        {
            perror("can't open port");
            return(-1);
        }
    }
    else if(comport == 2)
    {
        fd = open("/dev/ttyS1", O_RDWR | O_NOCTTY | O_NDELAY);
        if(-1 == fd)
        {
            perror("can't open serial port");
            return(-1);
        }
    }
    else if(comport == 3)
    {
        fd = open("/dev/ttyS2", O_RDWR | O_NOCTTY | O_NDELAY);
        if(-1 == fd)
        {
            perror("can't open serial port");
            return(-1);
        }
    }
    else if(comport == 4)
    {
        fd = open("/dev/ttyS3", O_RDWR | O_NOCTTY | O_NDELAY);
        if(-1 == fd)
        {
            perror("can't open serial port");
            return(-1);
        }
    }

    if(fcntl(fd, F_SETFL, 0) < 0)
    {
        printf("fcntl failed!\n");
    }
    else
        printf("fcntl = %d\n", fcntl(fd, F_SETFL, 0));

    if(isatty(STDIN_FILENO) == 0)
    {
        printf("standart input is not a terminal device\n");
    }
    else
        printf("istty success!\n");

    printf("fd - open = %d\n", fd);

    return fd;
}
