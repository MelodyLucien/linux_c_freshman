#include<stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include<string.h>

int main(){
 int fd =open("tt.txt",O_RDWR);
 if(fd!=-1)
 printf("fd is %d \n successful open a file!!\n",fd);
 
 fchmod(fd,S_IXUSR|S_IRUSR|S_IWUSR); 

 return 0;
}
