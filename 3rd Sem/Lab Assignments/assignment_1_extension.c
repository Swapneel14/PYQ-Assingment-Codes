#include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 typedef struct  student{
    char name[10];
    int roll;
    char phn[10];
    char adr[50];
 }stu;
 typedef struct sreg{
   int max;
   int count;
   stu **arr;
 }sreg;
 void initialize(sreg *list){
    if(list==NULL){
        return;
    }
    list->count=0;
    printf("Enter Max No. Of Students\n");
    scanf("%d",&list->max);
    list->arr =(stu **)malloc(sizeof(stu *)*list->max);
    for(int i=0;i<list->max;i++){
        list->arr[i]=NULL;
    }
 }
 void read(stu *s1){
    printf("Enter Name\n");
    scanf("%s",s1->name);
    printf("Enter Roll\n");
    scanf("%d",&s1->roll);
    printf("Enter Phone\n");
    scanf("%s",s1->phn);
    printf("Enter Adress\n");
    scanf("%s",s1->adr);
 }
 int add(sreg *list,stu *s){
      if(list==NULL){
        return 0;
      }
      for(int i=0;i<list->max;i++){
        if(list->arr[i]==NULL)continue;
        if(list->arr[i]->roll==s->roll){
            printf("Existing Student");
            return 0;
        }
      }
      for(int i=0;i<list->max;i++){
        if(list->arr[i]==NULL){
            list->arr[i]=s;
            list->count++;
            break;
        }
      }
      
      

      return 1;
 }
 stu* create(){
    stu *s1=(stu *)malloc(sizeof(stu));
    printf("Enter Name\n");
    scanf("%s",s1->name);
    printf("Enter Roll\n");
    scanf("%d",&s1->roll);
    printf("Enter Phone\n");
    scanf("%s",s1->phn);
    printf("Enter Adress\n");
    scanf("%s",s1->adr);
    return s1;
 }
 void display(stu *s){
    printf("Data of Student\n");
    printf("Name: %s\n",s->name);
    printf("Phn: %s\n",s->phn);
    printf("Adr: %s\n",s->adr);
    printf("Roll: %d\n",s->roll);
    
}
void displayAll(sreg *list){
    for(int i=0;i<list->max;i++){
        if(list->arr[i]!=NULL){
            display(list->arr[i]);
        }
    }
}
stu* get(sreg *list,int roll){
    for(int i=0;i<list->max;i++){
        if(list->arr[i]!=NULL&&list->arr[i]->roll==roll){
            return list->arr[i];
        }
    }
}
int delete(sreg*list,int roll){
    for(int i=0;i<list->max;i++){
        if(list->arr[i]!=NULL&&list->arr[i]->roll==roll){
            list->arr[i]=NULL;
            list->count--;
            return 1;
        }
    }
    return 0;
}
int modify(sreg*list,stu *s){
    for(int i=0;i<list->max;i++){
        if(list->arr[i]!=NULL&&list->arr[i]->roll==s->roll){
               list->arr[i]=s;
               return 1;
        }
    }
    return 0;
}
int count(sreg*list){
    return list->count;
}
int export(sreg *list, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return 0;
    }

    for (int i = 0; i < list->max; i++) {
        if (list->arr[i] != NULL) {
            fprintf(fp, "%s,%d,%s,%s\n",
                    list->arr[i]->name,
                    list->arr[i]->roll,
                    list->arr[i]->phn,
                    list->arr[i]->adr);
        }
    }

    fclose(fp);
    return 1;
}
int load(sreg *list, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return 0;
    }

    list->count = 0;

    while (!feof(fp)) {
        stu *s = (stu *)malloc(sizeof(stu));

        
        if (fscanf(fp, "%[^,],%d,%[^,],%[^\n]\n",
                   s->name, &s->roll, s->phn, s->adr) == 4) {
            
            add(list, s);
        } else {
            free(s); 
        }

        if (list->count >= list->max) break;
    }

    fclose(fp);
    return 1;
}
stu* createrecordfromfile(FILE *fp){
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return NULL;
    }
    stu *s = (stu *)malloc(sizeof(stu));
    if(fscanf(fp,"%s %d %s %s",s->name,&s->roll,s->phn,s->adr)!=4){
        free(s);
        return NULL;
    }
    return s;




}
void freestudent(stu * s){
    if(s!=NULL){
        free(s);
    }
}







 int main(){
    sreg list;
    initialize(&list);
    stu s1;
    //read(&s1);
    
   stu *s2=create();
   stu *s3=(stu *)malloc(sizeof(stu));
   s3=create();
   stu *s4=(stu *)malloc(sizeof(stu));
   s4=create();
    
    
   // add(&list,&s1);
    add(&list,s2);
    add(&list,s3);
    add(&list,s4);
    //hhdisplay(s2);
    //displayAll(&list);

    if (export(&list, "students.txt"))
        printf("Exported successfully!\n");

    // Create a new list to load into
    sreg loadedList;
    initialize(&loadedList);

    if (load(&loadedList, "students.txt"))
        printf("Loaded successfully!\n");
    printf("The Final Loaded List with all the students :- \n");
    displayAll(&loadedList);


    return 0;
 }