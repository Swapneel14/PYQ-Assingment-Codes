#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack{
   int top;
   int max_size;
   int *arr ;
} stack;

void initialize(stack *s,int max_size){
    s->top=-1;
    s->max_size=max_size;
    s->arr=malloc(max_size*sizeof(int));
    
}
int push(stack *s,int el){
    if(s->top+1==s->max_size)return 0;
    s->top++;
    s->arr[s->top]=el;
    
    return 1;

}
void display(stack *s){
    if(s->top==-1){
        printf(" Stack is Empty");
        return ;
    }
    printf("The Stack is \n");
    for(int i=0;i<=s->top;i++){
        printf("%d ",s->arr[i]);
    }
    printf("\n");
}
int pop(stack *s,int* el){
    if(s->top==-1){
        return 0;
    }
    int popped=s->arr[s->top];
    s->top--;
    *el=popped;
    return 1;


}
int isEmpty(stack *s){
    if(s->top==-1)return 1;
    else return 0;
    
}
int isFull(stack*s){
    if(s->top+1==s->max_size)return 1;
    return 0;
}
int size(stack *s){
    return s->top+1;
}
int freestack(stack *st){
    if(!st||!st->arr)return 0;
    free(st->arr);
    st->arr=NULL;
    st->top=-1;
    return 1;


}
void question2(){
    stack s1,s2;
    int m=0,n=0;
    printf("Enter M");
    scanf("%d",&m);
    printf("Enter N");
    scanf("%d",&n);
    initialize(&s1,m);
    initialize(&s2,n);
     int num;
    while (1) {
        scanf("%d", &num);
        if (num == -1) break;

        if (!isFull(&s1)) {
            push(&s1, num);
        } else if (!isFull(&s2)) {
            push(&s2, num);
        } else {
            printf("Both stacks are full.\n");
            break;
        }
    }
    int val;
    printf("Stack 2 elements: \n");
    while(!isEmpty(&s2)){
        pop(&s2,&val);
        printf("%d ",val);

    }
    printf("\n");
    printf("Stack 1 elements: \n");
    while(!isEmpty(&s1)){
        pop(&s1,&val);
        printf("%d ",val);

    }
    freestack(&s1);
    freestack(&s2);

}
int checkExpression() {
    char expr[200];
    printf("Enter a String:\n");
    scanf(" %[^\n]", expr); 

    stack s;
    initialize(&s, strlen(expr));
    int popped;

    for (int i = 0; i < strlen(expr); i++) {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(&s, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&s)) {
                freestack(&s);
                return 0; 
            }
            pop(&s, &popped);

            if ((ch == ')' && popped != '(') ||
                (ch == '}' && popped != '{') ||
                (ch == ']' && popped != '[')) {
                freestack(&s);
                return 0; 
            }
        }
    }

   if(!isEmpty(&s))return 0;
   freestack(&s);
   return 1;
}





int main(){
    if(checkExpression()){
        printf("Valid\n");
    }
    else{
        printf("Invalid\n");
    }


    question2();
    stack s1;
    int max_size1;
    printf("Enter Max size for This Stack\n");
    scanf("%d",&max_size1);
    
    initialize(&s1,max_size1);
    if(push(&s1,1)){
        printf("Pushed %d\n",1);
    }
    else{
        printf("Stack is full %d can't be Inserted",1);
    }
     if(push(&s1,2)){
        printf("Pushed %d\n",2);
    }
    else{
        printf("Stack is full %d can't be Inserted",2);
    }
     if(push(&s1,3)){
        printf("Pushed %d\n",3);
    }
    else{
        printf("Stack is full %d can't be Inserted",3);
    }
    display(&s1);
    int el=0;
    if(pop(&s1,&el)){
        printf("Popped Successfully,The element is %d\n",el);
    }
    display(&s1);
    

    return 0;
}