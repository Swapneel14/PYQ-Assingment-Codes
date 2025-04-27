//compare two strings//
#include<stdio.h>
int compare(char s[],char t[]){
    int s1=0;
    int s2=0;
    while(s[s1]!='\0'){
        s1++;
    }
    while(t[s2]!='\0'){
        s2++;
    }
    if(s1!=s2){
        return 0;
    }
    for(int i=0;i<s1;i++){
        if(s[i]!=t[i]){
            return 0;
        }
    }
    return 1;
}
void main(){
    char s[100],t[100];
    printf("Enter String 1: ");
    scanf("%s",s);
    printf("Enter String 2: ");
    scanf("%s",t);
    int ans = compare(s,t);
    printf("%d",ans);

}