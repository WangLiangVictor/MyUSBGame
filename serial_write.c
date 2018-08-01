#include "main_include.h"
#include "extern_function.h"

void serial_write(void *arg)
{
    int fd = 0;
    int nwrite = 0;
    int flag = 0;
    char buf[100] = {0};

    fd = *((int *)arg);

    while(1)
    {
        memset(buf, 0, 100);
        scanf("%s", buf);

        if((nwrite = write(fd, buf, strlen(buf))) < 0)
        {
            if(errno == EAGAIN)
            {
                printf("The fd has not been write yet. Please try later\n");
            }
        }
        else
        {
            printf("nwrite = %d\n", nwrite);
        }
    }
}
