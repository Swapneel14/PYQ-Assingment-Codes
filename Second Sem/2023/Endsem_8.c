#include<stdio.h>
void main(){
    FILE *f;
    f=fopen("Students.txt","w");
    int n;
    printf("Enter no. of Students: ");
    scanf("%d",&n);
    if(f==NULL){
        printf("Error Opening File");
        return ;
    }
    int roll,marks;
    char name[100];
    for(int i=1;i<=n;i++){
        printf("Enter Name:");
        scanf("%s",name);
        printf("enter marks: ");
        scanf("%d",&marks);
        printf("Enter Roll");
        scanf("%d",&roll);
        fprintf(f,"Name: %s\n Roll=%d\n Marks=%d",name,roll,marks);

    }
    fclose(f);
}