#include<stdio.h>
#include<conio.h>
#include<string.h>


#define max 10
typedef struct Student{
   char name[22];
   int roll;
   char phn[12];
   char adr[50];
} stu;
typedef struct{
    int count;
    stu reg[max];

}sreg;
int add(sreg *list,stu *s){
    if((*list).count>=max)return 0;
    for(int i=0;i<(*list).count;i++){
        if((*list).reg[i].roll==s->roll)return 0;
    }
    (*list).reg[(*list).count]=*s;
    list->count++;
    return 1;
}
stu getbyroll(sreg list,int roll){
    for(int i=0;i<list.count;i++){
        if(list.reg[i].roll==roll)return list.reg[i];
    }
    stu emp={"",0,"",""};
    return emp;
}
void readStudData(stu * s) {
    printf("Enter Student detail\n");
    printf("Enter Roll:");
    scanf("%d", &(s->roll));
    printf("Enter Name:");
    scanf("%s", s->name);
    printf("Enter Phone:");
    scanf("%s", s->phn);
    printf("Enter Address:");
    scanf("%s", s->adr);
}
int delete(sreg *list,int roll){
    for(int i=0;i<list->count;i++){
        if(list->reg[i].roll==roll){
            for(int j=i;j<(*list).count-1;j++ ){
                list->reg[j]=list->reg[j+1];
            }
            list->count--;
            return 1;
        }
    }
    return 0;
}
int modify( sreg *list,stu *s){
    for(int i=0;i<(*list).count;i++){
      if((*list).reg[i].roll=s->roll){
         (*list).reg[i]=*s;
         return 1;

      }

    }
    return 0;
}
void sortstudents(sreg *list){
    for(int i=0;i<(*list).count-1;i++){
        for(int j=i+1;j<(*list).count;j++){
            if(strcmp((*list).reg[i].name,(*list).reg[j].name)>0){
                 stu s=(*list).reg[i];
                 (*list).reg[i]=(*list).reg[j];
                 (*list).reg[j]=s;
            }
        }
    }
}
int studentcount(sreg *list){
    return list->count;
}
void displayAll(sreg *list){
    if(list==NULL){
        return ;
    }
    if(list->count==0){
        printf("No Students are in The List");
        return;
    }
    for(int i=0;i<list->count;i++){
        printf("Data of Student %d\n",i+1);
         printf("Name: %s\n",list->reg[i].name);
         printf("Roll: %d\n",list->reg[i].roll);
         printf("Phone: %s\n",list->reg[i].phn);
         printf("Adress: %s\n",list->reg[i].adr);
          printf("\n");
        printf("\n");
        printf("\n");
        printf("\n");
}

}

void displayStudData(stu * s) {
    printf("Printing Student detail\n");
    printf("Roll: %d\n", s->roll);
    printf("Name: %s\n", s->name);
    printf("Phone: %s\n", s->phn);
    printf("Address: %s\n", s->adr);

}
int export(sreg* list,char *filename){
    FILE *fp=fopen(filename,"w");
    if(fp==NULL)return 0;
    for(int i=0;i<list->count;i++){
        fprintf(fp,"%s,%d,%s,%s\n",
            list->reg[i].name,
            list->reg[i].roll,
            list->reg[i].phn,
            list->reg[i].adr

        
        );
    }
    fclose(fp);
    return 1;
}
int loaddata(sreg *list,char *file){
    FILE *fp=fopen(file,"r");
    if(fp==NULL)return 0;
    list->count=0;
    while (fscanf(fp, "%[^,],%d,%[^,],%[^\n]\n",   
                  list->reg[list->count].name,
                  &list->reg[list->count].roll,
                  list->reg[list->count].phn,
                  list->reg[list->count].adr) == 4) 
    {
        list->count++;                   
        if (list->count >= max) break;   
    }
    fclose(fp);
    return 1;


}
        



int main(){
   sreg list;
   list.count=0;
   stu s1;
   stu s2;
   stu s3;
   readStudData(&s1);
   readStudData(&s2);
   readStudData(&s3);
   add(&list,&s1);
   add(&list,&s2);
   add(&list,&s3);
   stu s4;
   readStudData(&s4);
   add(&list,&s4);
   displayAll(&list);
   sortstudents(&list);
   
   delete(&list,s2.roll);
  
   displayStudData(&s4);
   export(&list,"data.txt");
   if(loaddata(&list,"data.txt")){
    printf("Loading successfull\n");
   }
   else{
    printf("Loading unsuccessfull");
   }
   displayAll(&list);
   







   

  return 0;
}

