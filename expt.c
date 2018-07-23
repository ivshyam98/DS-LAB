#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
struct node{
char info;
struct node *left;
struct node *right;
};
typedef struct node* NODE;

NODE stk[10];

NODE maketree(NODE root,char exp[]){

int top=-1;
int i;
char symbol;

for(i=0;exp[i]!='\0';i++){

symbol=exp[i];
NODE temp;
temp=(NODE)malloc(sizeof(NODE));
temp->info=symbol;
temp->left=NULL;
temp->right=NULL;
if(isalnum(symbol)){
stk[top++]=temp;
}
else{
temp->right=stk[--top];
temp->left=stk[--top];
stk[top++]=temp;
}
}
return (stk[--top]);
}

int evaluate_tree(NODE root){
if(root==NULL){

printf("U didn't make the tree press 1 first\n");
return 0;
}
switch(root->info){
case '+':return(evaluate_tree(root->left)+evaluate_tree(root->right));break;
case '-':return(evaluate_tree(root->left)-evaluate_tree(root->right));break;
case '*':return(evaluate_tree(root->left)*evaluate_tree(root->right));break;
case '/':return(evaluate_tree(root->left)/evaluate_tree(root->right));break;
case '^':return(pow(evaluate_tree(root->left),evaluate_tree(root->right)));break;
case '$':return(pow(evaluate_tree(root->left),evaluate_tree(root->right)));break;
default:
return root->info-'0';
}
}
void main(){
NODE root;
root=NULL;
char expr[20];
int n;
int j;
printf("enter the expression\n");
scanf("%s",expr);
while(1){

printf("enter the choice\n");
printf("1:make treeeee\n2:evaluate_tree\n");
scanf("%d",&n);

switch(n){
case 1:root=maketree(root,expr);break;
case 2:j=evaluate_tree(root);
printf("evaluted value of postfix expr using tree = %d\n",j);
break;

default:printf("Enter the valid choice\n");
}
}
}
