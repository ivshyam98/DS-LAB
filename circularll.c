#include<stdio.h>
#include<malloc.h>
#include<ctype.h>
struct node{
int info;
struct node* link;
};
typedef struct node* NODE;
NODE insert_beg(NODE last,int item){

    NODE temp;
    temp=(struct node*)malloc(sizeof(struct node));
temp->info=item;
if(last==NULL){
    temp->link=temp;
return temp;
}
    else{
temp->link=last->link;
last->link=temp;
}
return last;
}
NODE insert_end(NODE last,int item){
 NODE temp,cur;
    temp=(NODE)malloc(sizeof(struct node));
    temp->info=item;
if(last==NULL){
    temp->link=temp;
last=temp;
    return last;
}
 temp->link=last->link;
last->link=temp;
last=temp;
return last;
}

NODE insert_pos(NODE last,int item,int pos){
NODE temp,prev,cur;
temp=(NODE)malloc(sizeof(struct node));
temp->info=item;

int count=1;
if(last==NULL && pos==1)
    {
temp->link=temp;
last=temp;
return last;
}
if(last==NULL && pos!=1)
{
    printf("invalid position\n");
    return last;
}
if(pos==1)
{
    temp->link=last->link;
last->link=temp;
    return last;
}
prev=NULL;
cur=last->link;
while(count!=pos && cur!=last)
{
        prev=cur;
    cur=cur->link;
count++;
}


if(count==pos)
{
       
   temp->link=cur;
 prev->link=temp;
   return last;
}
//if we want to insert at last
count++;
if(count==pos)
{
temp->link=last->link;
last->link=temp;
return temp;
}
printf("cantt insert\n");
return last;


}

NODE delete_beg(NODE last){
NODE cur;
if(last==NULL){
printf("cannot delete empty\n");
return last;
}
cur=last->link;

last->link=cur->link;
printf("dleeetd is=%d ",cur->info);
free(cur);
return last;
}
NODE delete_last(NODE last){
NODE cur,prev;
if(last==NULL){
printf("empty list\n");
return NULL;
}
if(last->link==last)
{
printf("deleted item is=%d ",last->info);
free(last);
return NULL;
}
cur=last->link;
prev=NULL;
while(cur!=last){
prev=cur;
cur=cur->link;
}
prev->link=last->link;
printf("deleted itemo is =%d",last->info);
free(last);
last=prev;
return last;
}

NODE delete_pos(NODE last,int pos){

if(last==NULL){
printf("empty list\n");
return NULL;
}
NODE cur,prev;
cur=last->link;
if(pos==1){
last->link=cur->link;
printf("deleted is =%d",cur->info);
free(cur);
return last;
}
int count=1;
prev=NULL;
while(count!=pos && cur!=last)
{
prev=cur;
cur=cur->link;
count++;
}
if(count==pos)
{

if(cur==last){
prev->link=last->link;
printf("deleetd last element=%d",cur->info);
free(cur);
last=prev;
return last;

}
prev->link=cur->link;
printf("deleetd item is=%d",cur->info);
free(cur);
return last;
}
printf("cant insert\n");
return last;
}
void display(NODE last){
    NODE temp;
if(last==NULL){
    printf("linked list is empty\n");
    return;
}
    temp=last->link;
    while(temp!=last){

    printf("%d ",temp->info);
        temp=temp->link;
    }
printf("%d",last->info);

return;

}
void main(){
NODE last;
int ch,pos,item;
last=NULL;
printf("enter the choice\n");
while(1){
printf("\n1:insert_beg\n2:insert_end\n3:insert_pos\n4:delete_beg\n:5:delete_last\n6:delete_pos\n7:display\n");

scanf("%d",&ch);
switch(ch){
case 1:printf("enter the item to insert\n");
scanf("%d",&item);
last=insert_beg(last,item);break;
case 2:printf("enter the item to insert\n");
scanf("%d",&item);
last=insert_end(last,item);break;
case 3:printf("enter the item to insert\n");
scanf("%d",&item);
printf("enter the position\n");
scanf("%d",&pos);
last=insert_pos(last,item,pos);break;
case 4:last=delete_beg(last);break;
case 5:last=delete_last(last);break;
case 6:printf("enter the position\n");
scanf("%d",&pos);
last=delete_pos(last,pos);break;
case 7:display(last);break;
default:printf("enter the valid choice\n");
}
}
}
