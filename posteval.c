#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int op1,op2;
int p[15];
int top=-1;
int eval(char post[]);
void main(){
char post[15];
printf("enter the postfix exp\n");
scanf("%s",post);
int x = eval(post);
printf("the value is %d\n",x);
}
int eval(char post[]){
for(int i=0;post[i]!='\0';i++){
if(isdigit(post[i])){
int y = (post[i]-'0');
p[++top] = y;
}
else{
if(top!=-1){
 op2 = p[top--];
 op1 = p[top--];
}
else{
printf("invalid exp");
exit(0);
}
switch(post[i]){
case '+':p[++top]=op1+op2;
break;
case '-':p[++top]=op1-op2;break;
case '*':p[++top]=op1*op2;break;
case '/':if(op2==0){
         printf("infinite\n");exit(0);
         }
         else{
         p[++top]=op1/op2;
         }
         break;
case '^':p[++top]=pow(op1,op2);
break;
default:printf("invalide exp");
}
}
}
if(top==0){
return(p[top]);}
else{
printf("Please enter a valid postfix expression\n");
exit(0);
}
}

