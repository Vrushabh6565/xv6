#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
int main(void) {
	char buff[256], buff1[256];
	int fd = open("mmaptest.txt", O_RDWR);
	printf(1,"==>%d\n", fd);
	char *addr = (char *) mmap(10,fd,0);
	char *addr1 = (char *) mmap(5,fd,0);
	printf(1,"mmap addr = > %s %s\n", &addr, &addr1);
	strcpy(buff, addr);
	strcpy(buff1, addr1);
	printf(1, "==%s==%s\n", buff,buff1);
	printf(1,"unmap==> %d\n",munmap((int)addr));
  	strcpy(buff, addr);
  	printf(1, "==%s==\n", buff);
  	close(fd);
	exit();
}

