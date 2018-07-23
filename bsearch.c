#include<stdio.h>
int bsearch(int key,int a[],int low,int high){
int mid;
if(low>high)
return -1;
mid=(low+high)/2;
if(key==a[mid])
return a[mid];
else if(key<a[mid])
return bsearch(key,a,low,mid-1);
else if(key>a[mid])
return bsearch(key,a,mid+1,high);
}


void main(){
int n;
int i;
int item;
int pos;

int a[20];

printf("enter the no. elements\n");
scanf("%d",&n);
printf("enter %d no. of elements for binary search\n",n);
for(i=0;i<n;i++){
scanf("%d",&a[i]);
}


printf("enter the item to be searched in the list\n");
scanf("%d",&item);
pos=bsearch(item,a,0,n-1);
if(pos==-1)
printf("item not found\n");
else
printf("item found at %d",pos-1);

}

