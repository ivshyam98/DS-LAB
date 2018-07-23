#include<stdio.h>
int gcd(int , int );
void main(){
int a,b;
int result = 0;

printf("enter two nos. to find their gcd\n");
scanf("%d%d",&a,&b);
result=gcd(a,b);
printf("the gcd of two nos. %d and %d is %d",a,b,result);
}
int gcd(int a, int b){
while(a!=b){
if(a==0)
return a;
else if(b==0)
return b;
else if(a>b){
return gcd(a-b,b);
}
else if(a<b){
return gcd(a,b-a);
}
}
return a;
}

