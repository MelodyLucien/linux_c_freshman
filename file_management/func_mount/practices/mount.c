#include<sys/mount.h>
#include<stdio.h>
int main(){

  int res=  mount("/dev/sdb1","disk1","vfat",0,"iocharset=utf8");
  if(res==0){
      perror("success!");
  }else{
      perror("error!!");
  }
  res=umount("disk1");
  if(res==0){
    perror("umount success!!");
  }else{
     perror("umount failed!!");
  }



  return 0;
}
