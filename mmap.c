#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
int main(void) {
	int fd = open("mmaptest.txt", O_RDWR);
	printf(1,"==>%d\n", fd);
	char *addr = (char *) mmap(10,fd,0);
	char buff[256];
  	strcpy(buff, addr);
  	printf(1, "%s\n", (char*)buff);
  	char buff2[256];
  	read(fd, buff2, 5);
  	printf(1, "%s\n", (char*)buff2);
  	char buff3[256];
  	read(fd, buff3, 2);
  	printf(1, "%s\n", (char*)buff3);
	exit();
}

