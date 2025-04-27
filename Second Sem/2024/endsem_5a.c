#include<stdio.h>//reverse string//
#include<string.h>
void reverse(char s[]){
    int n= strlen(s);
    int i=0;
    int j=n-1;
    while(i<=j){
        char t =s[i];
        s[i]=s[j];
        s[j]=t;
        i++;
        j--;
    }
    printf("%s",s);
}
void main(){
    char s[100];
printf("Enter Your String ");
scanf("%s",s);
reverse(s);
}