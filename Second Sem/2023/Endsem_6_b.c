#include<stdio.h>
int strl(char s[]){
    int l=0;
    while(s[l]!='\0'){
        l++;
    }
    return l;
}
void main(){
    char s[100];
    printf("Enter String: ");
    scanf("%s",s);
    int ans = strl(s);
    printf("The Length is %d",ans);
    
}