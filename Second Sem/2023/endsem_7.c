#include<stdio.h>
typedef struct {
    int real;
    int img;

}complex;
complex add(complex c1,complex c2){
   complex res ={c1.real+c2.real,c1.img+c2.img};
   return res;
}
void display(complex res){
    if (res.img>0){
        printf("%d+%di",res.real,res.img);
    }
    else{
        printf("%d%di",res.real,res.img);
    }
}
void main(){
    complex c1 , c2;
    printf("Enter the real part of the first number: ");
    scanf("%d",&c1.real);
    printf("Enter the imaginary part of the first number: ");
    scanf("%d",&c1.img);
    printf("Enter the real part of the second number: ");
    scanf("%d",&c2.real);
    printf("Enter the imaginary part of the second number: ");
    scanf("%d",&c2.img);
    complex res = add(c1,c2);
    display(res);
}
