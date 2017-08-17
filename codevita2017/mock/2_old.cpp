#include<bits/stdc++.h>
#define WRAP 1000000007
#define LL unsigned long long

using namespace std;

long int calcVitaSum(LL int n, LL int k)
{
    LL i,j;


    LL kEffective,extra,doublingStartAt, isNEven=0, mid;
    int isDoubling=0;

    if(n%2==0)
        isNEven=1;

    if(isNEven==0 || k<=(n/2))
        kEffective=k;
    else
        {
            isDoubling=1;
            kEffective=n/2 + 1 - isNEven;
            mid = n/2 + 1 - isNEven;
            extra = k-mid;
            doublingStartAt = mid-extra;



            printf("kEffective = %lld, extra = %llu, isNEven=%d\n", kEffective, extra, isNEven);
            printf("Doubling to begin at i>=%llu\n", doublingStartAt);
        }

    LL sum=1;
    LL temp=1;
    long double factor;

    if(isDoubling && doublingStartAt==0)
        sum=2;

    for(i=2;i<=kEffective;i+=2)
    {
        temp=temp*(n-i+1)*(n-i+2)/((i)*(i-1));

        if(isDoubling && i!=mid && i>=doublingStartAt)
        {
            sum=sum+2*temp;
            printf("%lluC%llu = %llu (Doubled)\n",n,i,temp);
        }
        else
        {
            sum=sum+temp;
            printf("%lluC%llu = %llu\n",n,i,temp);
        }
        if(sum>WRAP)
            sum=sum%WRAP;
    }

    return sum;
}

int main()
{

    LL n,k;

    while(1)
    {

    scanf("%llu %llu", &n, &k);

    LL sum = calcVitaSum(n,k);

    printf("%llu\n",sum);
    }
}
