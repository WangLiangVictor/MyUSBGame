#
#
#
cc = gcc
#
g_make = main.c open_serial.c set_serial.c serial_write.c serial_read.c
#
out = write_read_thread
#
#
#
all:$(g_make)
	$(cc) -g $(g_make) -o $(out) -lpthread
	rm -f *.o
#
clean:
	rm -f *.o $(out)
#
#
