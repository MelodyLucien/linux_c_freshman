#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

void
main(){

	char * file = "test";
	char * buf = "12345";
        char buf1[1024];
	int fd = open(file, O_CREAT|O_RDWR, 0777);
	int sk = lseek(fd, 10, SEEK_SET);
	int fr = write(fd, buf, 5);
        int res = read(fd,buf1,10);
        printf("%s\n",buf1);
	close(fd);
}
