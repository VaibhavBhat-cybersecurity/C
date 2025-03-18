#include<stdio.h>
int main()
{
    int i,a,n,t,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i>a[j]])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
return 0;
}