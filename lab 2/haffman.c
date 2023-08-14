#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX 6

int intArray[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;

int peek() {
   return intArray[front];
}

bool isEmpty() {
   return itemCount == 0;
}

bool isFull() {
   return itemCount == MAX;
}

int size() {
   return itemCount;
}  

void insert(int data) {

   if(!isFull()) {
	
      if(rear == MAX-1) {
         rear = -1;            
      }       

      intArray[++rear] = data;
      itemCount++;
   }
}

int removeData() {
   int data = intArray[front++];
	
   if(front == MAX) {
      front = 0;
   }
    itemCount--;
   return data;  
}

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
    struct node *parent;
}node;

node *createNode(int val){
    node *new = (node *) malloc(sizeof(node));
    new->data = val;
    new ->left = new->right = NULL;
    new->parent= NULL;
    return new;
}
void Inorder(node *root){
    if(root!=NULL){
        Inorder(root->left);
        printf("%d ",root->data);
        Inorder(root->right);
    }
}

void insert(node *root, int val)
{
        node *new = createNode(val);
        while (root != NULL)
        {
            if(root->data >= new->data)
            {
                if(root->left == NULL)
                {
                    root->left= new;
                    new->parent= root;
                    break;
                }
                root = root->left;
            }
            else 
            {
                if(root->right == NULL)
                {
                    root->right= new;
                    new->parent= root;
                    break;
                }
                root = root->right;
            }
        
        }
        return ;

}
node* minimum(node* root)
{
    while(root->left != NULL)
    {
        root= root->left;
    }
    return root;
}

node* maximum(node* root)
{
    while(root->right != NULL)
    {
        root= root->right;
    }
    return root;
}


node* successor(node* root, int val)
{
    node *target= searchNode(root, val);
    node *new = (node *) malloc(sizeof(node));
    
    if(target->right != NULL)
    {
        return minimum(target->right);
    }

    new= target->parent;
    while(new != NULL && target == new->right)
    {
        target= new;
        new= new->parent;
    }
    return new;
}


void preorder(node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

 void huffman(char )






int main(){
    char arr[]={'a','b','c'};
    int frequency[] = {3,4,2};
    int size;
    size=sizeof(arr)/sizeof(arr[0]);

}