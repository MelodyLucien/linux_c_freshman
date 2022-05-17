#include<iostream>
#include "main.h"

using namespace std;

extern int x;
extern int y;

int main(){
    cout<<"extern x:"<<x<<", y"<<y<<endl;
    return 0;
}
