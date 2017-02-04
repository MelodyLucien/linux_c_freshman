#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
   int fd,res;
   fd=open("/home/zhouhao2/linuxc/linux_c_freshman/file_management/func_chown/practices/ftest.txt",O_RDONLY);
   if(fd == -1){
    printf("error\n"); 
   }else{
     printf("open success!\n");
   }

   if((res=fchown(fd,1000,0))!=0){
     printf("fchown error,%d\n",res);
   }else{
     printf("fchown success,%d\n",res);
   }

   close(fd);
   return 0;
}
