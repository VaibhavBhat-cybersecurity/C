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
   void b_sort(int a[10],int n)
  {
     int t,i,j;
     for(i=0;i<n-1;i++)
       {
         for(j=0;j<n-(i+1);j++)
           {
             if(a[j]>a[j+1])
               {
                  t=a[j];
                  a[j]=a[j+1];
                  a[j+1]=t;
                  }
                }
             }
       }
    void display(int a[10],int n)
    {
       int i;
       for(i=0;i<n;i++)
         {
         printf("%d\t",a[i]);
         }
         printf("\n");
       }

    int main()
    {
      int a[10],n;
       printf("Enter the number of elements you want in the array: ");
       scanf("%d",&n);
       accept(a,n);
       printf("Entered Elements are:");
       display(a,n);
       b_sort(a,n);
       printf("Sorted Elements are:\n");
       display(a,n);
       return 0;
       }
