#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
int info;
struct node* left;
struct node* right;
};
typedef struct node* NODE;
NODE insert_item(NODE root,int item){
    NODE temp,cur,prev;
    temp=(NODE)malloc(sizeof(struct node));
    temp->info=item;
    temp->left=NULL;
    temp->right=NULL;
if(root==NULL){
    return temp;
}
char a[10];
 printf("enter the direction of insertion of node\n");
    scanf("%s",a);
cur=root;
prev=NULL;
int i;
for(i=0;i<strlen(a);i++){

        if(cur==NULL)break;
         prev=cur;
    if(a[i]=='R')
        cur=cur->right;
    else if(a[i]=='L')
        cur=cur->left;
        else
            printf("enter the directions as specified");
}
if(cur!=NULL || i!=strlen(a)){
    printf("insertion not possible\n");
    free(temp);
    return root;
}
if(a[i-1]=='R')
    prev->right=temp;
else
    prev->left=temp;
return root;
}

void inorder(NODE root){

if(root==NULL)
    return;
inorder(root->left);
printf("%d ",root->info);
inorder(root->right);
}
void preorder(NODE root){
if(root==NULL)
return;

printf("%d",root->info);
preorder(root->left);
preorder(root->right);
}
void postorder(NODE root){
if(root==NULL)
return;


postorder(root->left);
postorder(root->right);
printf("%d",root->info);
}

void PrintTree(NODE tp,int spaces)
{
  int i;
if(tp==NULL)

  if( tp != NULL )
  {
    PrintTree( tp->right, spaces + 3 );
    for( i = 0; i < spaces; i++ )
      printf(" ");
    printf("%d\n",tp->info);
    PrintTree( tp->left, spaces + 3 );
  }
}
int main()
{
    NODE root;
    root=NULL;
    printf("Hello world!\n");
    printf("welcome to binary tree program\n");
    printf("-------------------------------\n");
    int item,n;
    for(;;){
            printf("enter the choice of opertion\n");

            printf("1:inserting a node\n2:inorder\n 3:preorder\n 4:postorder\n 5:destination");
            scanf("%d",&n);
    switch(n){
    case 1:printf("enter the node to be inserted to tree\n");
    scanf("%d",&item);
        root=insert_item(root,item);break;
        case 2:inorder(root);break;
case 3:preorder(root);
break;
case 4:postorder(root);
break;


case 5:PrintTree(root,0);break;
        default:printf("enter the valid choice\n");

    }
    }
    return 0;
}
