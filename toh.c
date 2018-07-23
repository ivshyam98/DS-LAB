#include<stdio.h>
void toh(int ,char ,char ,char);
void main(){
int n;
printf("Enter the no. of disks\n");
scanf("%d",&n);
toh(n,'A','B','C');
}
void toh(int n,char src,char temp,char dest){
if(n==0)
return;
else{
toh(n-1,src,dest,temp);
printf("Move %d disk from %c to %c\n",n,src,dest);
toh(n-1,temp,src,dest);
}
}

