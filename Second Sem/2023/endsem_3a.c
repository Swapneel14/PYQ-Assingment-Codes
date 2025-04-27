//example of call by reference//
#include<stdio.h>
void change(int *x){
    *x=100;
}
void main(){
    int x=10;
    change(&x);
    printf("%d",x);
}
//output will be 100//as in Call by Reference the changes in the function will 
//modify the original variable//
