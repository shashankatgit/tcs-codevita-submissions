#include<stdio.h>
#include<math.h>

int main()
{

    long long int n;

    scanf("%lld",&n);

    long long sum=0;
    long int digit=0;
    long long int j,i;
    long int tmp;

    long int count;
    long int mul;

    for(j=0;j<=n;j++)
    {
        tmp=pow(2,(1+2*j));
        digit+=(tmp%10);
        digit=digit%10;
    }

    count = floor(log(n)/log(2));

    mul=2;
    for(i=1;i<=count;i++)
    {
        digit*= mul;
        mul*=2;
        digit%=10;
    }


    printf("%ld",digit);

 return 0;
}
