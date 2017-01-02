#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
   int fd;
   fd=open("/home/zhouhao2/linuxc/linux_c_freshman/file_chmod_attribute/ftest.txt",O_RDONLY);
   if(fd == -1){
    printf("error\n");
   
   }else{
   
     printf("open success!\n");
   }


   if(fchown(fd,1000,1000)){
   
     printf("fchown sucess\n");
   }else{
   
     printf("fchown error\n");
   }

   return 0;
}
