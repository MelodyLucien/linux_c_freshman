#include<stdio.h>
#include<stdlib.h>
typedef struct student{
  int num;
  int age;
  int score;
  struct student *next;
}stu;

int n;

stu *create(){
   stu *head,*temp,*tail;
   n=0;
   head = tail=(stu *)malloc(sizeof(stu));
   char ch =' ';
   while(ch != 'q'){
       printf("please input the student 's num,age,score\n:");

       temp = (stu *)malloc(sizeof(stu));

       if(temp == NULL){
          printf("the mem is not enough!!!");
   
       }else{
          scanf("%d %d %d",&(temp->num),&(temp->age),&(temp->score));
       }
       temp->next =NULL;
       tail->next=temp;
       tail=temp;

       ch = getchar();
   }

   temp=head;
   while(temp!= NULL){
      printf("stu:\n num:%d\nage:%d\nscore:%d\n",temp->num,temp->age,temp->score);
      temp=temp->next;
   }

   return NULL;
}

int main(){
  printf("hello world!!!\n");
  create();
  return 0;
}
