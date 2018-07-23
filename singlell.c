#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

struct node{
int info;
struct node *link;
};
typedef struct node* NODE;
NODE insert_beg(int item,NODE first){

    NODE temp;
    temp=(struct node*)malloc(sizeof(struct node));
temp->info=item;
if(first==NULL)
    temp->link=NULL;
    else
temp->link=first;
first=temp;
return first;
}
NODE insert_last(int item,NODE first){
    NODE temp,cur;
    temp=(struct node*)malloc(sizeof(struct node));
temp->info=item;

     temp->link=NULL;
if(first==NULL){
    first=temp;
    return first;
}
cur=first;
while(cur->link!=NULL)
    cur=cur->link;
    cur->link=temp;
    return first;
}
NODE insert_pos(int item,int pos,NODE first){
NODE temp,prev,cur;
temp=(struct node*)malloc(sizeof(struct node));
temp->info=item;
temp->link=NULL;
int count=1;
if(first==NULL && pos==1)
    return temp;
if(first==NULL){
    printf("invalid position\n");
    return first;
}
if(pos==1){
    temp->link=first;
first=temp;

    return first;
}
prev=NULL;
cur=first;
while(count!=pos && cur!=NULL){
        prev=cur;
    cur=cur->link;
count++;
}
if(count==pos){
        temp->link=prev->link;

   prev->link=temp;
   return first;
}
printf("invalid position\n");
return first;
}

void freenode(NODE x){
free(x);
}
NODE delete_beg(NODE first){
NODE temp;
if(first==NULL){
    printf("list is empty\n");
    return first;}
temp=first;
first=temp->link;
temp->link=NULL;
freenode(temp);
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
while(cur->link!=NULL){
        prev=cur;
    cur=cur->link;
    }
    printf("deleted node is=%d",cur->info);
    freenode(cur);
prev->link=NULL;
return first;

}
NODE delete_pos(NODE first,int pos){
NODE cur,prev;

if(first==NULL || pos<=0){
    printf("invalid position\n");
    return NULL;
}
if(pos==1){
    cur=first;
    first=first->link;
    freenode(cur);
    return first;
}
cur=first;
prev=NULL;
int count=1;
while(count!=pos && cur!=NULL){
    prev=cur;
    cur=cur->link;
    count++;
}
if(count==pos){
    prev->link=cur->link;
    return first;
}
printf("invalid position\n");
return first;
}
void display(NODE first){
    NODE temp;
if(first==NULL){
    printf("linked list is empty\n");
    return;
}
    temp=first;
    while(temp!=NULL){

    printf("%d ",temp->info);
        temp=temp->link;
    }

}

int main(){
NODE first=NULL;
int ch,item,pos;
printf("WELCOME LINK LIST PROGRAM\n");
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
