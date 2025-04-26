#include<stdio.h>
int rgcd(int s,int b,int p){
    if(p==1){
        return p;
    }
    if(s%p==0&&b%p==0){
        return p;
    }
    rgcd(s,b,p-1);
}
void main(){
    int n1,n2,p;
    printf("Enter Your Numbers: ");
    scanf("%d%d",&n1,&n2);
    if(n1<=n2){
        p=n1;
    }
    else{
        p=n2;
    }
    int ans=rgcd(n1,n2,p);
    printf("The GCD is : %d",ans);
}