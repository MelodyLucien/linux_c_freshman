#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

// ssize_t read(int fd, void *bufftemp, size_t count);
//off_t lseek(int fd, off_t offset, int whence);

// can not use read cause no override in c language
void rread(int fd,void *bufftemp){

   int count =read(fd,bufftemp,10);
   if(count!=0){
     ((char *)bufftemp)[10]='\0';
     printf("read cotent:%s\n",(char *)bufftemp);
   }else{
     printf("read error !!\n");
   }
}

int main(){
   int fd,res;
   char bufftemp[1024];
   fd=open("/home/zhouhao2/linux_c_freshman/file_management/func_chown/practices/ftest.txt",O_RDWR);
   if(fd == -1){
     perror("open error\n");
   }else{
     printf("open success!\n");
   }
   char a='\0';
   printf("after open !!%c\n",a);
   rread(fd,bufftemp);

   int offset=lseek(fd,5,SEEK_CUR);

   printf("after lseek!!\n");
   rread(fd,bufftemp);

//   bufftemp="zhouhao2"; error why ?

   offset=write(fd,"zhouhao2",8);

   fsync(fd);

   printf("after write!!\n");

   rread(fd,bufftemp);

   if((res=fchown(fd,1000,0))!=0){
     printf("fchown error,%d\n",res);
   }else{
     printf("fchown success,%d\n",res);
   }

   close(fd);

printf("umask");
umask(S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH|S_IRUSR | S_IWUSR);
fd=open("tt",O_CREAT);

   return 0;
}
