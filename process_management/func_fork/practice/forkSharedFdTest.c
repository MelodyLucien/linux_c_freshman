#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>

void printPid(){

  printf("hello\n");
  printf("getpid %ld,getppid %ld\n",(long)getpid(),(long)getppid());
  printf("sizeof long %d\n",(int)sizeof(long));
  printf("sizeof int %d\n",(int)sizeof(int));
}

void openFile(int number){
int  i;
for (i=0;i<number;i++){
//open a file
 int sharedFD=open("/home/zhouhao2/linux_c_freshman/process_management/func_fork/practice/test.txt",O_RDONLY);
 printf("fd is %d\n",sharedFD);

 if(sharedFD==-1){
   printf("error!!\n");
 }else{
   printf("i get a fd!!!\n");
 }
}
}

void openFileStr(char * path){

//open a file
 int sharedFD=open(path,O_RDONLY);
 printf("fd is %d\n",sharedFD);

 if(sharedFD==-1){
   printf("error!!\n");
 }else{
   printf("i get a fd!!!\n");
 }
}

void loop(){
   while(1){
       ;
 }
}

//this program will print twice hello
int main(){
  printPid();
  pid_t cpid;
  openFile(1);
 if(( cpid=fork())>0){
     printPid();
     openFileStr("/home/zhouhao2/linux_c_freshman/process_management/func_fork/practice/test4.txt");
     loop();
 }else if(cpid==0){
     printPid();
     openFile(1);
     openFileStr("/home/zhouhao2/linux_c_freshman/process_management/func_fork/practice/test3.txt");
     loop();
 }

  return 0;
}
