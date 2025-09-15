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
node* merge(node* n1,node* n2){
  if(n1==NULL||n2==NULL){
    return (n1==NULL)?n2:n1;
}
node* new=NULL;
new=(n1->data>=n2->data)?n1:n2;
node* ans=new;
if(new==n1)n1=n1->next;
else n2=n2->next;
while(n1!=NULL&&n2!=NULL){
  if(n1->data>=n2->data){
    new->next=n1;
    new=new->next;
    n1=n1->next;
  }
  else{
    new->next=n2;
    new=new->next;
    n2=n2->next;
  }
}
node* rem=(n1==NULL)?n2:n1;
while(rem!=NULL){
  new->next=rem;
  new=new->next;
  rem=rem->next;
}
return ans;




}
void checkmerge(){
  node* d1=NULL;
  node* d2=NULL;
  int n1,n2;
  printf("Enter no. of elements for first list\n");
  scanf("%d",&n1);
  for(int i=1;i<=n1;i++){
    int el;
    printf("Enter element: ");
    scanf("%d",&el);
    d1=addsorted(d1,el);
 }
 printf("Enter no. of elements for sceond list\n");
  scanf("%d",&n2);
  for(int i=1;i<=n2;i++){
    int el;
    printf("Enter element: ");
    scanf("%d",&el);
    d2=addsorted(d2,el);
 }
  
  
  node* ans=merge(d2,d1);
  print(ans);
}
node* sortList(node* head){
    if(head == NULL || head->next == NULL) return head;

    int swapped;
    node *ptr1;
    node *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while(ptr1->next != lptr){
            if(ptr1->data < ptr1->next->data){ 
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while(swapped);

    return head;
}

int main(){
  int choice;
   checkmerge();
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
   case 6:{
    if(n1 == NULL){
        printf("List is Empty, cannot sort\n");
        break;
    }
    n1 = sortList(n1);
    printf("List after sorting:\n");
    print(n1);
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

