#include<stdio.h>
int main(){
  int a,b,c;
  int *p1,*p2,*p3;
  printf("Enter two numbers\n");
  scanf("%d %d",&a,&b);
  p1=&a;
  p2=&b;
  p3=&c;
  *p3=*p1+*p2;
  printf("Sum=%d",*p3);
  return 0;
}