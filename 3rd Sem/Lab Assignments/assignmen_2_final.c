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
    if(s->top==0){
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
int top(stack *s){
if(s->top==-1)return 0;
return s->arr[s->top];

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
        if(isFull(&s1)&&isFull(&s2)){
            printf("Both Stacks are Full");
            break;
        }
        printf("Enter Element: ");
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

int checkExpression() {//Balanced Parenthesis Program
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

  void postfix(){//Calculate a PostFix Expression
    char c[200];
    printf("Enter Your Postfix Operation");
    scanf("%[^\n]",c);
    int n=strlen(c);
    stack s;
    initialize(&s,n);

    for(int i=0;i<n;i++){
	  char ch= c[i];
	if(ch>='0'&&ch<='9')push(&s,ch-'0');
	else{
	     int op1=0,op2=0;
	     pop(&s,&op2);
	     pop(&s,&op1);
	     if(ch=='+') push(&s,(op1+op2));
	     if(ch=='-')push(&s,(op1-op2));
	     if(ch=='*')push(&s,(op1*op2));
	     if(ch=='/')push(&s,(op1/op2));

	
	
	}

    
    
    }
    int ans=0;
    pop(&s,&ans);
    printf("%d",ans);

  
  
  
  
  }
int priority(char c){
	if(c=='+'||c=='-')return 10;
	if(c=='/'||c=='*')return 20;
	 return 100;
}
void intopost(){//Infix to Postfix Operation
 char s[100],r[100];
 printf("Enter Your Infix Operation:  ");
 scanf("%[^\n]",s);
 int n =strlen(s);
 stack s1;
 initialize(&s1,n);
 int k=0;
 for(int i=0;i<n;i++){
     char ch=s[i];
     if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9')){//for operands
          r[k]=ch;
	  k++;
     }
     else if(ch=='('){  //for (
	     push(&s1,ch);
        
     }
     else if(ch==')'){ // for )
           int p=0;
	   
	   while(!isEmpty(&s1)&&top(&s1)!='('){
	          pop(&s1,&p);
		  r[k]=p;
		  k++;
		  

                  
                 			  
	    }
	   pop(&s1,&p);

  }
     else{ //for operators
	     
        while(!isEmpty(&s1)&&top(&s1)!='('&&priority(s[i])<=priority(top(&s1))){
	  int p=0;
	  pop(&s1,&p);
	  r[k]=p;
	  k++;

	
	}
	push(&s1,s[i]);
     
     }
     
     
 
 }
 while(!isEmpty(&s1)){
 int p=0;
 pop(&s1,&p);
 r[k]=p;
 k++;
 
 }
 r[k]='\0';


 printf("Ans is :%s\n",r);
 




}



int main(){
	
      	//postfix();
	intopost();
    if(checkExpression()){
        printf("Valid\n");
    }
    else{
        printf("Invalid\n");
    }


    question2();
    stack s1;
    int max_size1;
    printf("Enter Max Size of The Stack\n");
    scanf("%d",&max_size1);
    initialize(&s1,max_size1);
    int choice;
    int run=1;
    while(run){
    printf("Stack Choices:-\n");
    printf("1.Push\n");
    printf("2.Pop\n");
    printf("3.Display\n");
    printf("4.if Full\n");
    printf("5.if Empty\n");
    printf("6.size\n");
    printf("7.Exit\n");
    scanf("%d",&choice);
    switch(choice){
         case 1: {     
            int num=0;
			printf("enter number of element for push\n");
                        scanf("%d",&num);
			for(int i=0;i<num;i++){
				int el=0;
			 printf("Enter element: ");
			 scanf("%d",&el);
			 
			 if(isFull(&s1)){
			    printf("Stack is Full now");
			    break;
			 }
			 push(&s1,el);

			}
		break;
         }
		
	
	case 3:{
	       display(&s1);
	       break;
	       
	       }
	 case 2:{
		int p=0;
		pop(&s1,&p);
		printf("Popped Element is %d\n",p);
		break;
		
		}
	 case 4:{
		 if(isFull(&s1))printf("The stack is Full now\n");
		 else printf("The Stack is Not full now\n");
		 break;
		}
	 case 5:{
	         	if(isEmpty(&s1))printf("The Stack is Empty\n");
			else printf("The stack is not empty\n");
			break;
		}
	 case 6:{
		  printf("Stack size is : %d\n",size(&s1));
		  break;
		
		}
	 case 7:{
		 run=0;
		 break;
		
		}
    
    }
    
    
    }
    
    
    

    return 0;
}
