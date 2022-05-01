#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
int main(void) {
	char buff1[256] = "ABCDEFG", buff2[128], buff3[256], buff4[128];
	int unmap = 0;
	int fd = open("mmaptest.txt", O_RDWR);
	int fd1 = open("README", O_RDWR);
	read(fd, buff3, 7);
	printf(1,"Internal mapping : ");
	if(!strcmp(buff1, buff3))
		printf(1,"PASS\n");
	else
		printf(1,"FAIL\n");
	printf(1,"Internal mmap by lseek : ");
	lseek(fd, 3, SEEK_SET);
	read(fd, buff2, 4);
	if(!strcmp(buff2, "DEFG"))
		printf(1,"PASS\n");
	else
		printf(1,"FAIL\n");
	char *addr =(char*) mmap(11, fd1, 22);
	lseek(fd1, 22, SEEK_SET);
	read(fd1, buff2, 11);
	buff2[12] = '\0';
	printf(1, "mmap syscall : ");
	if(!strcmp(buff2, addr))
		printf(1,"PASS\n");
	else
		printf(1,"FAIL\n");
	printf(1, "unmap syscall : ");
	unmap = munmap((int)addr);
	if(unmap == 1)
		printf(1,"PASS\n");
	else
		printf(1,"FAIL\n");
	close(fd);
	read(fd, buff4, 10);
	printf(1, "Internal munmap : ");
	if(!strcmp(buff4, ""))
		printf(1,"PASS\n");
	else
		printf(1,"FAIL\n");
	printf(1, "%d", strcmp(buff2, addr));
	exit();
}
