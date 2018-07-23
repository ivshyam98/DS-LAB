#include<stdio.h>
#include<malloc.h>

struct node{
int info;
struct node* left;
struct node* right;
};
typedef struct node* NODE;

NODE insertion(NODE root,int item){

NODE temp,cur,prev;
temp=(NODE)malloc(sizeof(struct node));
temp->info=item;
temp->left=NULL;
temp->right=NULL;
if(root==NULL)
{
root=temp;
return root;
}
if(item<root->info){
temp->right=root;
temp->left=NULL;
root->left=temp;
return temp;
}
if(item>root->info && root->right==NULL){
//NODE nn;
//root;
root->right=temp;
temp->left=root;
temp->right=NULL;
return root;
}

cur=root;
prev=NULL;
while(cur!=NULL)//seee this imp imp
{
if(item>cur->info)
{
prev=cur;
cur=cur->right;
}
else{
temp->right=cur;
temp->left=prev;
prev->right=temp;
cur->left=temp;
return root;
}

}
if(cur==NULL){
prev->right=temp;
temp->left=prev;
temp->right=NULL;
return root;
}
}

void display(NODE root){
if(root==NULL)
printf("empty list\n");
else{
while(root!=NULL)
{
printf("%d ->",root->info);
root=root->right;
}
}
}


void main(){
NODE root;
root=NULL;
int item,ch;
printf("welcome to orderly doubly linked list\n");
printf("enter the choice\n");
while(1){
printf("\n1:insertion\n2:display\n");
scanf("%d",&ch);
switch(ch){
case 1:printf("enter the item\n");
scanf("%d",&item);
root=insertion(root,item);break;
case 2:display(root);break;
default:printf("enter the vaklid choice\n");
}
}
}
