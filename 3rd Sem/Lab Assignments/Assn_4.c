#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


typedef struct listNode{
	int data;
       struct listNode* next;
}node;


node* create(int val){
	
     node* l1=(node*)malloc(sizeof(node));
      l1->data=val;
      l1->next=NULL;
      return l1;
      
}
node* addsorted(node* head,int elem){

       node* new=create(elem);
	if(head==NULL){
	  return new;
	}
	if(elem>=head->data){
	  new->next=head;
	  return new;
	}
	node *prev=NULL;
	node* curr=head;
	while(curr!=NULL&&curr->data>=elem){
		prev=curr;
		curr=curr->next;
  }
	prev->next=new;
	new->next=curr;
	return head;
	
}
int ispresent(node* head,int el){
    if(!head)return 0;
    node* temp=NULL;
    temp=head;
    int i=0;
    while(temp!=NULL){
        if(temp->data==el){
            printf("Element Found at %dth Node\n",i+1);
            return 1;
        }
        i++;
        temp=temp->next;
 }
 return 0;
}
node* deletenode(node* head,int el){
    node* temp=NULL;
      temp=head;
      if(el==head->data){
        temp=temp->next;
        free(head);
        return temp;
      }
    node* prev=NULL;
    while(temp!=NULL){
        if(temp->data==el){
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    return head;
     
    
}
void print(node* head){
    node* temp=NULL;
    temp=head;
    while(temp!=NULL){
      printf("%d->",temp->data);
      temp=temp->next;
    }
    printf("NULL\n");

}

node* reversenode(node* head){
  if(head==NULL||head->next==NULL){
    return head;
  }
  node* prev=head;
  node* temp=head->next;
  while(temp!=NULL){
    node* front=temp->next;
    temp->next=prev;
    prev=temp;
    temp=front;
  }
  head->next=NULL;
  return prev;
}
void updatenode(node* head){
  if(head==NULL){
    printf("Head is NULL");
    return;
  }
  srand(time(NULL));
  node* cur=head;
  while(cur!=NULL){
    int val=rand()%10;
    cur->data+=val;
    cur=cur->next;
 }
}

int main(){
  int choice;
   
   node* n1=NULL;
   int run=1;
   while(run==1){
    printf("1.Add Node in Sorted List.\n 2.Delete Node\n 3.isPresent\n 4.Print List\n");
   printf("Enter Choice\n");
   scanf("%d",&choice);
    switch (choice)
   {
   case 1:{
        int n;
        printf("Enter How many nodes you want to add\n");
        scanf("%d",&n);
        for(int i=0;i<n;i++){
          int el;
          printf("Enter Element: ");
          scanf("%d",&el);
          n1=addsorted(n1,el);
        }
    break;
      }
      case 2:{
        int el;
        printf("Enter element to delete");
        scanf("%d",&el);
        n1=deletenode(n1,el);
        break;
      }
      case 3:{
          int el;
          printf("Enter element to check: ");
          scanf("%d",&el);
          if(ispresent(n1,el)){
            printf("Present\n");
          }
          else{
            printf("Not Present\n");
          }
      }
   case 4:
        if(n1==NULL){
          printf("List Is Empty\n");
          break;
        }
        print(n1);
        break;
    case 5:{
      n1=reversenode(n1);
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

