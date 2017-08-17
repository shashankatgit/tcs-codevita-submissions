#include<stdio.h>

int main()
{

 int sum=0;
 int a;
 int num;

 scanf("%d",&a);
 int i;
 for(i=0;i<a;i++)
    {
        scanf("%d",&num);
        sum+=num;
    }

if(sum%a==0) printf("Yes 2");
else printf("No");

 return 0;
}
