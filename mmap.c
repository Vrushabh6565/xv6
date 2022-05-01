#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
int main(void) {
	char buff[256], buff1[256];
	int fd = open("mmaptest.txt", O_RDWR);
	char *addr = (char *) mmap(10,fd,0);
	//char *addr1 = (char *) mmap(5,fd,0);
	read(fd, buff1, 7);
	printf(1, "%s | %s\n", buff,buff1);
	printf(1,"unmap %d\n",munmap((int)addr));
  	close(fd);
	exit();
}

