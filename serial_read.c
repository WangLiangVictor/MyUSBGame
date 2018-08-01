#include "main_include.h"
#include "extern_function.h"

void serial_read(void *arg)
{
    fd_set rd = {0};
    int fd = 0;
    int nread = 0;
    char buf[100] = {0};

    fd = *((int *)arg);

    FD_ZERO(&rd);
    FD_SET(fd, &rd);

    while(FD_ISSET(fd, &rd))
    {
        if(select(fd + 1, &rd, NULL, NULL, NULL) < 0)
        {
           perror("select");
        }
        else
        {
            memset(buf, 0, 100);
            while((nread = read(fd, buf, sizeof(buf))) > 0)
            {
                    printf("%s\nnread = %d\n", buf, nread);
            }
        }

//        globe = getchar();
    }
}
