#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
   int a[5] = {1,2,3,4,5};
   a[3]=9;
   cout<< sizeof(a)<<endl;
   cout<<*(a+3)<<endl;
   cout<< sizeof(*(a))<<endl;
   return 0 ;

}
