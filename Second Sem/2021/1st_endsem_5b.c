/*Write a program to compute the factorial of a number, n. 
Here, n is an input given by the user.*/
//I am using recursing method//
#include<stdio.h>

int fact(int n){
    int ans;
    if(n==1){
        return 1;
    }
    ans= n*fact(n-1);
return ans;
}
void main(){
    int n;
    printf("Enter No: ");
    scanf("%d",&n);
    int ans = fact(n);
    printf("The Answer is :  %d",ans);

}