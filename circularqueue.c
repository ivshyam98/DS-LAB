#include<stdio.h>
#define MAX 5
int cq[MAX];
int f=-1,r=-1;
int c=0;
void in(int item);
void de();
void dis();
void main()
{
int n=1,ch;
int item;
while(n>0){
printf("\n1.insert\n2.delect\n3.display\n");
scanf("%d",&ch);
switch(ch){
case 1:printf("enter the item\n");
scanf("%d",&item);
in(item);
break;
case 2:de();
break;
case 3:dis();
break;
default:n=0;
}
}
}
void in(int item){
if(c==MAX){
printf("its full\n");
return;
}
if(r==-1){
f=r=0;
}
else{
r=(r+1)%MAX;
}
cq[r]=item;
c++;
}
void de(){
if(f==-1){
printf("empty\n");
return;
}
int pop = cq[f];
if(f==r){
f=r=-1;
}
else{
f=(f+1)%MAX;
c--;
}
printf("%d",pop);
}
void dis(){
if(f==-1){
printf("empty\n");
return;
}
int t=c;
for(int i=f;t!=0;i=(i+1)%MAX)
{
printf("%d",cq[i]);
t--;
}
}

