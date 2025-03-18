#include<stdio.h>
void accept(int a[10],int n)
{
  int i;
  for(i=0;i<n;i++)
    {
      printf("Enter a[%d]:",i);
      scanf("%d",&a[i]);
      }
   }
 int search(int a[10],int n,int x)
 {
   int i;
   for(i=0;i<n;i++)
     {
     if(a[i]==x)
       {
       return i;
       }
     }
   return i;
  }

  int main()
{
  int a[10],n,x,i,p;
  printf("Enter the number of elements you want in an array:\n");
  scanf("%d",&n);
  accept(a,n);
  printf("Enter the element for searching:");
  scanf("%d",&x);
  p=search(a,n,x);

  if(p==n)
  {
    printf("%d is not present in an array\n",x);
  }
  else
  {
    printf("%d is found at a[%d] position\n",x,p);
  }
  return 0;
}
