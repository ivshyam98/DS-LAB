#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
struct node{
int info;
struct node *left;
struct node *right;
};
typedef struct node* NODE;
NODE insert_beg(int item,NODE first){

    NODE temp;
    temp=(struct node*)malloc(sizeof(struct node));
temp->info=item;
temp->left=NULL;
if(first==NULL)
    temp->right=NULL;
    else
temp->right=first;
first=temp;
return first;
}
NODE insert_last(int item,NODE first){
    NODE temp,cur;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->info=item;
     temp->right=NULL;
if(first==NULL){
    first=temp;
    temp->left=NULL;
    return first;
}
cur=first;
while(cur->right!=NULL)
    cur=cur->right;
    cur->right=temp;
    temp->left=cur;
    return first;
}
NODE insert_pos(int item,int pos,NODE first){
NODE temp,prev,cur;
temp=(struct node*)malloc(sizeof(struct node));
temp->info=item;
temp->left=NULL;
temp->right=NULL;
int count=1;
if(first==NULL && pos==1)
    return temp;
if(first==NULL){
    printf("invalid position\n");
    return first;
}
if(pos==1){
    temp->right=first;
first->left=temp;
first=temp;
    return first;
}
prev=NULL;
cur=first;
while(count!=pos && cur!=NULL){
        prev=cur;
    cur=cur->right;
count++;
}
if(count==pos){
        temp->right=prev->right;
   prev->right=temp;
if(cur!=NULL)
   cur->left=temp;
   temp->left=prev;
   return first;
}
printf("invalid position\n");
return first;
}

void freenode(NODE x)
{
free(x);
}

NODE delete_beg(NODE first){
NODE temp;
if(first==NULL){
    printf("list is empty\n");
    return first;
    }
if(first->right==NULL){
temp=first;
temp->right=NULL;
free(temp);
first=NULL;
return first;
}
temp=first;
printf("deleted node is=%d",first->info);

first=first->right;
first->left=NULL;
free(temp);
return first;
}
NODE delete_last(NODE first){
NODE prev,cur;
if(first==NULL){
    printf("empty list");
    return first;
}
cur=first;
prev=NULL;
while(cur->right!=NULL){
        prev=cur;
    cur=cur->right;
    }
    printf("deleted node is=%d",cur->info);
    freenode(cur);
prev->right=NULL;
return first;

}
NODE delete_pos(NODE first,int pos){
NODE cur,prev;

if(first==NULL || pos<=0){
    printf("invalid position\n");
    return NULL;
}
if(pos==1&&(first->right!=NULL)){
    cur=first;
    first=first->right;
    first->right->left=NULL;
    freenode(cur);
    return first;
}
if(first->right==NULL&&pos==1){
free(cur);
first=NULL;
return first;
}
cur=first;
prev=NULL;
int count=1;
while(count!=pos && cur!=NULL){
    prev=cur;
    cur=cur->right;
    count++;
}
if(count==pos){
    prev->right=cur->right;
if(cur!=NULL)
    cur->right->left=prev;
    freenode(cur);
    return first;
}
printf("invalid position\n");
return first;
}
void display(NODE first){
    NODE temp;
if(first==NULL){
    printf("doubly linked list is empty\n");
    return;
}
    temp=first;
    while(temp!=NULL){

    printf("%d ",temp->info);
        temp=temp->right;
    }

}

int main(){
NODE first=NULL;
int ch,item,pos;
printf("WELCOME doubly LINK LIST PROGRAM\n");
printf("---------------------------\n");
for(;;){
    printf("enter the choice\n1:insert_front\n2:delete_front\n3:insert_last\n4:delete_last\n5:insert_position\n6:delete_position\n7:display\n");
    scanf("%d",&ch);
    switch(ch){
    case 1:printf("enter the elemnt to insert\n");
    scanf("%d",&item);
    first=insert_beg(item,first);break;
    case 2:first=delete_beg(first);break;
    case 3:printf("enter the element\n");
    scanf("%d",&item);
    first=insert_last(item,first);break;
    case 4:first=delete_last(first);break;
    case 5:printf("enter the postion and elemnet\n");
    scanf("%d%d",&pos,&item);
    first=insert_pos(item,pos,first);break;
    case 6:printf("enter the position of elemnt\n");
    scanf("%d",&pos);
    first=delete_pos(first,pos);break;
    case 7:display(first);break;
    default:exit(0);
    }
}
return 0;
}
