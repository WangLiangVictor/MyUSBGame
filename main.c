#include "main_include.h"
#include "extern_function.h"

#define FIFO "/tmp/myfifo"

char globe = 0;

int main()
{
    char fd = 0;
    int i = 0;
    char wbuf = 0;
    char buf[100] = {0};
    pthread_t id1 = {0};
    pthread_t id2 = {0};

    int ret = 0;

    if((fd = open_port(fd, 1)) < 0)
    {
        perror("open_port error");
        return;
    }
    printf("open_port success!\n");

    if((i = set_opt(fd, 115200, 8, 'N', 1)) < 0)
    {
        perror("set_opt error");
        return;
    }
    printf("set_opt success!\n");


    ret = pthread_create(&id1, NULL, (void *)serial_read, &fd);
    if(ret != 0)
    {
        perror("pthread_create1");
    }

    ret = pthread_create(&id2, NULL, (void *)serial_write, &fd);
    if(ret != 0)
    {
        perror("pthread_create2");
    }

    while(1)
    {
        fd = getchar();
        wbuf = getchar();
        scanf("%c", &fd);
        write(fd, &wbuf, 1);
        putchar(fd);
    }


    pthread_join(id1, NULL);
    pthread_join(id2, NULL);

    exit(0);
}
