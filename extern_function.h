extern int open_port(int fd, int comport);
extern set_opt(int fd, int nspeed, int nbits, char nevent, int stop);
extern void serial_read(void *arg);
extern void serial_write(void *arg);
