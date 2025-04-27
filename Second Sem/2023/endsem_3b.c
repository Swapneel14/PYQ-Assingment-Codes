//2023-3(b)
#include<stdio.h>
void fibo(int n,int f0,int f1){
    if(n==0){
        return;
    }
    int f2=f1+f0;
    printf("%d ",f2);
    fibo(n-1,f1,f2);
}
void main(){
    int n;
    printf("Enter The Value of n: ");
    scanf("%d",&n);
    if(n>0){
        printf("%d ",0);
    }
    if(n>1){
        printf("%d ",1);
    }
    if(n>2){
        fibo(n-2,0,1);
    }

}