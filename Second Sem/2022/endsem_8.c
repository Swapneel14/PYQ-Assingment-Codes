#include<stdio.h>
typedef struct complex{
    int real;
    int img;

};
void add(int x1,int y1,int x2,int y2){
int r=x1+x2;
int c= y1+y2;

if(c>0){
    printf("Final answer=%d + %di",r,c);
}
else{
    int x=-c;
    printf("Final answer=%d - %di",r,x);
}
}
void main(){
    struct complex n1,n2;
    printf("Enter real part of first complex");
    scanf("%d",&n1.real);
    printf("Enter img part of first complex");
    scanf("%d",&n1.img);
    printf("Enter real part of second complex");
    scanf("%d",&n2.real);
    printf("Enter img part of 2nd complex");
    scanf("%d",&n2.img);
    add(n1.real,n1.img,n2.real,n2.img);
}
