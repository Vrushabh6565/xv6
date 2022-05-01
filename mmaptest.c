#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
int main(void) {
	char buff[256], buff1[256], buff3[256];
	int fd = open("mmaptest.txt", O_RDWR);
	printf(1,"hello\n");
	read(fd, buff1, 17);
	printf(1, "%s\n", buff1);
	read(fd, buff3, 20);
	printf(1, "%s\n", buff3);
  	close(fd);
	exit();
}

