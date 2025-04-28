//Copy File using command line arguments//
#include<stdio.h>
 
int main(int argc, char *argv[]){
FILE *s,*t;
char ch;
if(argc!=3){
    return 1;
}
s=fopen(argv[1],"r");
if(s==NULL){
    printf("Error");
    return 1;
}
t=fopen(argv[2],"w");

if(t==NULL){
    printf("Error");
    return 1;
}
while (1)
{
    ch=fgetc(s);
    if(ch==EOF){
        break;
    }
    fputc(ch,t);
}
fclose(s);
fclose(t);
printf("File Copied");
return 0;


}