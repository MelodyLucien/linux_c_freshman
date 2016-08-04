#include<stdio.h>
int main()
{
  int sum = 0 ;
  int i = 0;
  int n =0;
  printf("input a number");
  printf("\n");
  scanf("%d",&n);
  for(;i<n+1;i++ ){
    sum = sum+i;
  }

  printf("the result is %d",sum);
  printf("\n");

   return 0;
}
