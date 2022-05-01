#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
int main(void) {
	char buff[256], buff1[256];
	int fd = open("mmaptest.txt", O_RDWR);
	read(fd, buff1, 7);
	printf(1, "%s\n",buff1);
	read(fd, buff, 1);
	printf(1, "%s\n",buff);
  	close(fd);
	exit();
}

