#include<stdio.h>
#include<dirent.h>

int main(int argc,char* agrv[]){
DIR* dp;
struct dirent* dirp;

if(argc!=2){
  printf("usage:lsdirectory_name\n");
  return 1;
}
if((dp=opendir(agrv[1]))==NULL){
  printf("cannotopen%s",agrv[1]);
  return 1;
}
while((dirp=readdir(dp))!=NULL){
  printf("%s\n",dirp->d_name);
}
closedir(dp);
return 0;
}

