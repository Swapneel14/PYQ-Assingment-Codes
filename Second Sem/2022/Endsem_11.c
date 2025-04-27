#include<stdio.h>
void con(char s[],char t[]){
int s1=0,t1=0;
while( s[s1]!='\0'){
    s1++;
}
while(t[t1]!='\0'){
    t1++;
}
char ans[100];
int k=0;
for(int i=0;i<s1;i++){
    ans[k]=s[i];
    k++;
}
for(int i=0;i<t1;i++){
    ans[k]=t[i];
    k++;
}
ans[k]='\0';
printf("Concatenated String is : %s\n",ans);
}
void main(){
    char s[100],t[100];
    printf("Enter String 1: ");
    scanf("%s",s);
    printf("Enter String 2: ");
    scanf("%s",t);
    con(s,t);
}

