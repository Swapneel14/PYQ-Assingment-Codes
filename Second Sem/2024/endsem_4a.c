//swap using the fucntion void swap(*int,*int)//
#include<stdio.h>

void swap(int *a,int *b){
     *a=*a+*b;
     *b=*a-*b;
     *a=*a-*b;
}
void main(){
    int a,b;
    printf("Enter value of a: ");
    scanf("%d",&a);
    printf("Enter value of b: ");
    scanf("%d",&b);
    printf("Before swap\n a=%d ,b=%d\n",a,b);
    swap(&a,&b);
    printf("after swap\n a=%d ,b=%d\n",a,b);
}