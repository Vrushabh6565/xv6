#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
int main(void) {
	int fd = open("mmaptest.txt", O_RDWR);
	printf(1,"==>%d\n", fd);
	char *addr = (char *) mmap(10,fd,2);
	char buff[256];
  	strcpy(buff, addr);
  	printf(1, "%s\n", (char*)buff);
  	printf(1, "XV6_TEST_OUTPUT : File content from mmap: %s\n", (char*)buff);
	exit();
}

