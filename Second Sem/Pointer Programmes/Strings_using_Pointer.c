#include<stdio.h>
void reverse(char *s){//Reverse String//
    int i=0;
    int j=0;
   
    while( *(s+i)!='\0'){
      i++;
    }
    char ans[100];
    for(int k=i-1;k>=0;k++){
      ans[j]=*(s+k);
      j++;
    }
    ans[j]='\0';
    printf("Reverse is :  %s\n",ans);
}
void len(char *s){//Length of a string//
    int i=0;
   
    while( *(s+i)!='\0'){
      i++;
    }
    printf("The Length is :  %d\n",i);
}
void compare(char *s,char *t){//Compare 2 string//
    int i=0;
   
    while( *(s+i)!='\0'){
      i++;
    }
    int j=0;
   
    while( *(t+j)!='\0'){
      j++;
    }
    if(i!=j){
        printf("Not Identical\n");
        return;
    }
    for(int k=0;k<i;k++){
        if(*(s+k)!=*(t+k)){
            printf("Not Identical\n");
            return;
        }
    }
    printf("Identical\n");
}
void concatinate(char *s,char *t){//concatenate 2 strings//
    int i=0;
   
    while( *(s+i)!='\0'){
      i++;
    }
    int j=0;
   
    while( *(t+j)!='\0'){
      j++;
    }
    int k=0;
    char ans[100];
    char *an= ans;
    for(int a=0;a<i;a++){
       *(an+k)=*(s+a);
       k++;
    }
    for(int a=0;a<j;a++){
        *(an+k)=*(t+a);
        k++;
    }
    *(an+k)='\0';
    printf("Concatinated String :  %s\n",ans);
}
void copy(char *s,char *t){
    int i=0;
   
    while( *(s+i)!='\0'){
      i++;
    }
    for(int m=0;m<i;m++){
        *(t+m)=*(s+m);
    }
    *(t+i)='\0';

}

int main(){
    char s1[100],t1[100];
    printf("Enter String S");
    scanf("%s",s1);
    printf("Enter String T");
    scanf("%s",t1);
    compare(s1,t1);
    len(s1);
    len(t1);
    concatinate(s1,t1);
    /*reverse(s1);
    reverse(t1);*/
    char t[100];
    copy(s1,t);
    printf("Copied String of S to a new string : %s",t);
    return 0;

}
