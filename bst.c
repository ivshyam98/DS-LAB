
#include<stdio.h>
#include<malloc.h>
struct node{
int info;
struct node *left;
struct node *right;
};
typedef struct node* NODE;

NODE insert_bst(NODE root,int item){
NODE cur,prev,temp;
temp=(NODE)malloc(sizeof(NODE));
temp->info=item;
temp->left=NULL;
temp->right=NULL;

if(root==NULL)
return temp;
cur=root;
prev=NULL;
while(cur!=NULL){
prev=cur;
if(item>cur->info)
cur=cur->right;
else
cur=cur->left;
}
if(item>prev->info)
prev->right=temp;
else
prev->left=temp;

return root;
}

void display(NODE root){
NODE cur;
cur=root;
if(cur==NULL)
return;
display(cur->left);
printf("%d\t",cur->info);
display(cur->right);

}

void PrintTree(NODE tp,int spaces)
{
  int i;

  if( tp != NULL )
  {
    PrintTree( tp->right, spaces + 3 );
    for( i = 0; i < spaces; i++ )
      printf(" ");
    printf("%d\n",tp->info);
    PrintTree( tp->left, spaces + 3 );
  }
}





void main()
{
int item,n;
NODE root;
root=NULL;
for(;;){
printf("\nchoice\n1:insert\n2:display\n3:destination\n");
scanf("%d",&n);
switch(n){
case 1:printf("enter the item to insert\n");
scanf("%d",&item);
root=insert_bst(root,item);break;
case 2:display(root);break;
case 3:PrintTree(root,0);break;
default:printf("enter a valid choice\n");
}
}
}
