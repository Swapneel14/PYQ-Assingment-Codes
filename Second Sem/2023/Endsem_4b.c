//Reverse String//
#include<stdio.h>
void reverse(char s[]){
   
    int l=0;
    while(s[l]!='\0'){
        l++;
    }
    char ans[l];
    int k=0;
    for(int i=l-1;i>=0;i--){
     ans[k]=s[i];
     k++;
    }
    ans[k]='\0';
    printf("Reversed String : %s",ans);
}
void main(){
    char s[100];
    printf("Enter String two reverse: ");
    scanf("%s",s);
    reverse(s);
    
}