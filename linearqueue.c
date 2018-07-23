#include<stdio.h>
#define MAX 5
int lq[MAX];
int f=-1,r=-1;
void in(int item);
void de();
void dis();
void main()
{
int n=1,ch;
int item;
while(n>0){
printf("1.insert\n2.delect\n3.display\n");
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
if(r==MAX-1){
printf("its  full\n");
return;
}
if(r==-1){
f=r=0;
}
else{
r++;
}
lq[r]=item;
}
void de(){
if(f==-1){
printf("its empty\n");
return;
}
int pop = lq[f];
if(f==0&&r==0){
f=r=-1;
}
else{
f++;
}
printf("item is %d",pop);
}
void dis(){
if(f==-1){
printf("its empty\n");
return;
}
for(int i=f;i<=r;i++){
printf("%d ",lq[i]);
}
}

