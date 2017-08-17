#include<stdio.h>

int main()
{
 long int i,j,k;

 long int n;
 long int sum;
 long int x;
 int flag=1;
 int ar[100000];

 scanf("%ld",&n);
 for(i=0;i<n;i++)
 {
    scanf("%d",&ar[i]);
 }

 scanf("%d",&x);

 for(i=0;i<n && flag;i++)
  {
    sum=0;
    for(j=i+1;j<n && flag;j++)
     {
        if((sum=ar[i]+ar[j])>=x)
         continue;

        for(k=j+1;k<n && flag;k++)
        {
            if(sum+ar[k]==x)
            {
                printf("True");
                flag=0;
            }
        }
     }
  }

if(flag==1)
    printf("False");
 return 0;
}
