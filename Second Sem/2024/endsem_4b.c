#include<stdio.h>
long int fact(int n){
    if(n==1){
        return 1;
    }
 int ans = n*fact(n-1);
 return ans;
}
void main(){
    int n;
    printf("Enter No.");
    scanf("%d",&n);
    if(n==0){
        printf("%d",1);
    }
    int ans= fact(n);
    printf("%d",ans);
}