#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct node {
    int val;
    struct node *left;
    struct node *right;
} treenode;
//Question:-1
treenode* create(int val) {
    treenode* newnode = (treenode*)malloc(sizeof(treenode));
    newnode->val = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

treenode* insertBST(treenode* root, int val) {
    if (root == NULL) {
        return create(val);
    }
    if (val <= root->val) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }
    return root;
}

int getcount(treenode* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + getcount(root->left) + getcount(root->right);
}

int isEmpty(treenode* t) {
    return (t == NULL);
}

void preorderprint(treenode* root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    preorderprint(root->left);
    preorderprint(root->right);
}

int preorder(treenode* root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return 0;
    }
    printf("Preorder Traversal: ");
    preorderprint(root);
    printf("\n");
    return 1;
}

void inorderprint(treenode* root) {
    if (root == NULL) return;
    inorderprint(root->left);
    printf("%d ", root->val);
    inorderprint(root->right);
}

int inorder(treenode* root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return 0;
    }
    printf("Inorder Traversal: ");
    inorderprint(root);
    printf("\n");
    return 1;
}

void postorderprint(treenode* root) {
    if (root == NULL) return;
    postorderprint(root->left);
    postorderprint(root->right);
    printf("%d ", root->val);
}

int postorder(treenode* root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return 0;
    }
    printf("Postorder Traversal: ");
    postorderprint(root);
    printf("\n");
    return 1;
}
//Question-2:-

int height(treenode* root){
    if(root==NULL||(root->left==NULL&&root->right==NULL))return 0;

    int lh=height(root->left);
    int rh=height(root->right);

    int sub_h=(lh>=rh)?lh:rh;
    return (1+sub_h);


}
int max_el(treenode *t) {
    if (t == NULL) {
        printf("Tree is empty.\n");
        return -1; 
    }
    while (t->right != NULL) {
        t = t->right;
    }
    return t->val;
}

int min_el(treenode* root){
    if(root==NULL){
        printf("Tree is Empty\n");
        return -1;
    }
    while (root->left!=NULL){
       root=root->left;
    }
    return root->val;
    
    
}

int isequal(treenode* t1,treenode* t2){
    if(t1==NULL&&t2==NULL)return 1;
    if(t1==NULL||t2==NULL)return 0;

    if(t1->val!=t2->val)return 0;

    return (isequal(t1->left,t2->left)&&isequal(t1->right,t2->right));
    
}
treenode* findMin(treenode* t) {
    while (t && t->left != NULL)
        t = t->left;
    return t;
}

treenode* inorder_successor(treenode*root,int key){
    treenode* node=NULL;
    while(root!=NULL){
      if(key<root->val){
        node =root;
        root=root->left;
      }
      else if(key>root->val){
        root=root->right;
      }
      else{
        node=findMin(root->right);
        break;
      }
    }
    return node;
}

treenode* delete(treenode* root,int val,int* s){
    if(root==NULL){
        *s=0;
        return NULL;
    }
    if(val<root->val){
        root->left=delete(root->left,val,s);
    }
    else if(val>root->val){
        root->right=delete(root->right,val,s);
    }
    else{
        *s=1;
         if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
         else if (root->left == NULL) {
            treenode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            treenode* temp = root->left;
            free(root);
            return temp;
        }

        
        else {
           
            treenode* succ = findMin(root->right);

            
            root->val = succ->val;

            
            root->right = delete(root->right, succ->val, s);
        }
    }
}


//2023-2(b)
void print_internal(treenode* root){
    if(root==NULL||(root->left==NULL&&root->right==NULL))return;
    printf("%d ",root->val);
    print_internal(root->left);
    print_internal(root->right);
}
int main() {
    treenode *root1 = NULL, *root2 = NULL;
    int choice, val, size, success, run = 1;


       while (run) {
        printf("\n\n===== MENU =====\n");
        printf("1. Insert into BST\n");
        printf("2. Check if Empty\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Inorder Traversal\n");
        printf("6. Count Nodes\n");
        printf("7. Get Height\n");
        printf("8. Get Min & Max\n");
        printf("9. Delete Node\n");
        printf("10. Compare Two Trees (isequal)\n");
        printf("11. Print Internal Nodes\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &size);
                for (int i = 0; i < size; i++) {
                    printf("Enter value %d: ", i + 1);
                    scanf("%d", &val);
                    root1 = insertBST(root1, val);
                }
                break;

            case 2:
                if (isEmpty(root1))
                    printf("Tree is Empty.\n");
                else
                    printf("Tree is NOT Empty.\n");
                break;

            case 3:
                printf("Preorder: ");
                preorderprint(root1);
                printf("\n");
                break;

            case 4:
                printf("Postorder: ");
                postorderprint(root1);
                printf("\n");
                break;

            case 5:
                printf("Inorder: ");
                inorderprint(root1);
                printf("\n");
                break;

            case 6:
                printf("Total Nodes: %d\n", getcount(root1));
                break;

            case 7:
                printf("Height of Tree: %d\n", height(root1));
                break;

            case 8:
                printf("Min: %d, Max: %d\n", min_el(root1), max_el(root1));
                break;

            case 9:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                root1 = delete(root1, val, &success);
                if (success)
                    printf("Node deleted successfully.\n");
                else
                    printf("Value not found in tree.\n");
                break;

            case 10:
                printf("Creating second tree for comparison...\n");
                printf("Enter number of nodes: ");
                scanf("%d", &size);
                for (int i = 0; i < size; i++) {
                    printf("Enter value %d: ", i + 1);
                    scanf("%d", &val);
                    root2 = insertBST(root2, val);
                }
                if (isequal(root1, root2))
                    printf("Both trees are equal!\n");
                else
                    printf("Trees are NOT equal.\n");
                break;
                     
            case 11:
                 print_internal(root1);
            case 12:
                run = 0;
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
