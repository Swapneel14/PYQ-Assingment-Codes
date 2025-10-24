#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct digitnode
{
    int digit;
    struct digitnode *next;
} number;
typedef struct polyNode
{
    int coeff;
    int exp;
    struct polyNode *next;
} poly;
typedef struct Node
{
    char name[50];
    struct Node *next;
    struct Node* prev;
} node;

number *newdigit(int d)
{
    number *n = (number *)malloc(sizeof(number));
    n->digit = d;
    n->next = NULL;
    return n;
}

number *insertathead(number *n, number *dig)
{
    dig->next = n;
    return dig;
}

number *reverse(number *n)
{
    number *prev = NULL;
    number *curr = n;
    while (curr != NULL)
    {
        number *nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

number *stringtolist(char num[], int *sign)
{
    int len = strlen(num);
    *sign = 1;
    number *head = NULL;
    for (int i = 0; i < len; i++)
    {
        char ch = num[i];
        if (ch == '-')
        {
            *sign = -1;
            continue;
        }
        if (ch == '+')
            continue;
        head = insertathead(head, newdigit(ch - '0'));
    }
    return head;
}

number *add_digit(number *d1, number *d2)
{
    number *dummy = newdigit(-1);
    number *curr = dummy;
    int carry = 0;
    while (d1 != NULL || d2 != NULL || carry)
    {
        int x = (d1 ? d1->digit : 0);
        int y = (d2 ? d2->digit : 0);
        int sum = x + y + carry;
        carry = sum / 10;
        curr->next = newdigit(sum % 10);
        curr = curr->next;
        if (d1)
            d1 = d1->next;
        if (d2)
            d2 = d2->next;
    }
    return dummy->next;
}

number *subtraction(number *a, number *b)
{
    int borrow = 0;
    number *dummy = newdigit(-1);
    number *curr = dummy;
    while (a != NULL)
    {
        int da = a->digit - borrow;
        int db = (b ? b->digit : 0);
        if (da < db)
        {
            da += 10;
            borrow = 1;
        }
        else
            borrow = 0;
        curr->next = newdigit(da - db);
        curr = curr->next;
        a = a->next;
        if (b)
            b = b->next;
    }
    number *res = dummy->next;

    return res;
}

void print(number *a)
{
    if (a == NULL)
    {
        printf("Invalid Number\n");
        return;
    }
    a = reverse(a);
    while (a && a->digit == 0 && a->next)
    {
        a = a->next;
    }
    printf("The Number is :- ");
    number *curr = a;
    while (curr != NULL)
    {
        printf("%d", curr->digit);
        curr = curr->next;
    }
    printf("\n");
    a = reverse(a);
}

poly *newPolyNode(int coeff, int exp)
{
    poly *n = (poly *)malloc(sizeof(poly));
    n->coeff = coeff;
    n->exp = exp;
    n->next = NULL;
    return n;
}
poly *insertPoly(poly *head, int coeff, int exp)
{
    poly *n = newPolyNode(coeff, exp);
    if (!head || head->exp < exp)
    {
        n->next = head;
        return n;
    }
    poly *curr = head;
    while (curr->next && curr->next->exp >= exp)
        curr = curr->next;
    if (curr->exp == exp)
        curr->coeff += coeff;
    else
    {
        n->next = curr->next;
        curr->next = n;
    }
    return head;
}
poly *addpoly(poly *p1, poly *p2)
{
    poly *res = NULL;
    while (p1)
    {
        res = insertPoly(res, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2)
    {
        res = insertPoly(res, p2->coeff, p2->exp);
        p2 = p2->next;
    }
    return res;
}
poly *subtract_poly(poly *p1, poly *p2)
{
    poly *res = NULL;
    while (p1)
    {
        res = insertPoly(res, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2)
    {
        res = insertPoly(res, -p2->coeff, p2->exp);
        p2 = p2->next;
    }
    return res;
}
void printPoly(poly *p)
{
    if (!p)
    {
        printf("0\n");
        return;
    }
    poly *curr = p;
    while (curr)
    {
        if (curr->exp == 0)
            printf("%d", curr->coeff);
        else if (curr->exp == 1)
            printf("%dx", curr->coeff);
        else
        {
            printf("%dx^%d", curr->coeff, curr->exp);
        }
        if (curr->next)
        {
            if (curr->next->coeff > 0)
                printf("+");
        }
        curr = curr->next;
    }
}
node *createperson(char name[])
{
    node *person = (node *)malloc(sizeof(node));
    strcpy(person->name, name);
    person->next = NULL;
    person->prev=NULL;
    return person;
}

node *circular(node *head, char name[])
{
    node *new = createperson(name);
    if (!head)
    {
        new->next = new;
        new->prev=new;
        return new;
    }
    node *curr = head;
    while (curr->next != head)
    {
        curr = curr->next;
    }
    new->next = curr->next;
    new->prev=curr;
    head->prev=new;
    curr->next = new;
    return head;
}
node *getNodeAt(node *head, int pos)
{
    node *curr = head;
    for (int i = 0; i < pos; i++)
        curr = curr->next;
    return curr;
}
void josephus(node *head, int S)
{
    node *prev = NULL;
    node *curr = head;
    
    while (curr->next != curr)
    {
        for (int i = 0; i < S; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        printf("Evicted Person :- %s\n", curr->name);
        prev->next = curr->next;
        free(curr);
        curr = prev->next;
    }
    printf("Winner is :- %s\n", curr->name);
    free(curr);
}
void enhancedjosephus(node* head,int n){
    node *prev = NULL;
    srand(time(0));
    node *curr = head;
    while(curr->next!=curr){
      int skip = (rand() % (2 * n + 1)) - n;
       if(skip==0)skip=1;
       printf("Skip Value is %d\n",skip);

       int steps=abs(skip);
       for(int i=0;i<steps;i++){
          curr=(skip>0)?curr->next:curr->prev;

       }    
         printf("Evicted Person :- %s\n", curr->name);
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        node* del=curr;
        curr=(skip>0)?curr->next:curr->prev;
        free(del);


    }
    printf("Winner is %s",curr->name);
}
int main()
{

    int con = 1;
    while (con)
    {
        int c = 0;
        printf("\n");
        printf("1. Large Number using Linked List (Add/Subtract)\n");
        printf("2. Polynomial using Linked List (Add/Subtract)\n");
        printf("3. Josephus Game using Circular Linked List\n");
        printf("4. Enhanced Josephus (Random S & Direction)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
        {
            char num1[100], num2[100];
            printf("Enter number 1:- ");
            scanf("%s", num1);
            printf("Enter number 2:- ");
            scanf("%s", num2);
            int sign1 = 0, sign2 = 0;
            number *n1 = stringtolist(num1, &sign1);
            number *n2 = stringtolist(num2, &sign2);
            printf("Choose operation (1-Add / 2-Subtract): ");
            int op;
            scanf("%d", &op);
            number *ans = NULL;
            if (op == 1)
                ans = add_digit(n1, n2);
            else
                ans = subtraction(n1, n2);
            print(ans);
            break;
        }
        case 2:
        {
            int n1, n2;
            printf("Enter number of terms for polynomial 1: ");
            scanf("%d", &n1);
            poly *p1 = NULL;
            for (int i = 0; i < n1; i++)
            {
                int coeff, exp;
                printf("Enter coeff and exp: ");
                scanf("%d %d", &coeff, &exp);
                p1 = insertPoly(p1, coeff, exp);
            }
            printf("Enter number of terms for polynomial 2: ");
            scanf("%d", &n2);
            poly *p2 = NULL;
            for (int i = 0; i < n2; i++)
            {
                int coeff, exp;
                printf("Enter coeff and exp: ");
                scanf("%d %d", &coeff, &exp);
                p2 = insertPoly(p2, coeff, exp);
            }
            printf("Choose operation (1-Add / 2-Subtract): ");
            int op;
            scanf("%d", &op);
            poly *res = NULL;
            if (op == 1)
                res = addpoly(p1, p2);
            else
                res = subtract_poly(p1, p2);
            printf("Resultant Polynomial: ");
            printPoly(res);
            break;
        }
        case 3:
        {
            srand(time(0));
            int n;
            printf("Enter number of players: ");
            scanf("%d", &n);
            char name[50];
            node *head = NULL;
            for (int i = 0; i < n; i++)
            {
                printf("Enter name of player %d: ", i + 1);
                scanf("%s", name);
                head = circular(head, name);
            }
            int skip;
            printf("Enter number of people to skip: ");
            scanf("%d", &skip);
            int start = rand() % n;
            printf("Starting Position is %d\n", start);
            head = getNodeAt(head, start);
            printf("Starting player is %s\n", head->name);
            josephus(head, skip);
            return 0;
        }
        case 4:{
             srand(time(0));
            int n;
            printf("Enter number of players: ");
            scanf("%d", &n);
            char name[50];
            node *head = NULL;
            for (int i = 0; i < n; i++)
            {
                printf("Enter name of player %d: ", i + 1);
                scanf("%s", name);
                head = circular(head, name);
            }
            
            int start = rand() % n;
            printf("Starting Position is %d\n", start);
            head = getNodeAt(head, start);
            printf("Starting player is %s\n", head->name);
            enhancedjosephus(head,n);
        }
        }
    }
    return 0;
}
