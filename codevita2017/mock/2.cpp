#include<bits/stdc++.h>
#define WRAP 1000000007
#define LL long long

using namespace std;

long int calcVitaSum(long long int n, long long int k)
{
    LL i,j;


    LL kEffective,extra,doublingStartAt, isNEven=0, mid;
    int isDoubling=0;

    if(n%2==0)
        isNEven=1;

    if(isNEven==0 || isNEven==1)
        kEffective=k;
    else
        {


            isDoubling=1;
            kEffective=n/2 + 1 - isNEven;
            mid = n/2 + 1 - isNEven;
            extra = k-mid;
            doublingStartAt = mid-extra;



//            printf("kEffective = %lld, extra = %lld, isNEven=%d\n", kEffective, extra, isNEven);
//            printf("Doubling to begin at i>=%lld\n", doublingStartAt);
        }

    long long sum=1;
    long long temp=1;
    LL factor;


//    if(doublingStartAt==0)
//        sum=2;

    for(i=2;i<=kEffective;i+=2)
    {
        factor=(n-i+1)*(n-i+2)/((i)*(i-1));
        temp=temp*factor;


        if(isDoubling && i!=mid && i>=doublingStartAt)
        {
            sum=sum+2*temp;
//            printf("%dC%d = %d (Doubled)\n",n,i,temp);
        }
        else
        {
            sum=sum+temp;
//            printf("%dC%d = %d\n",n,i,temp);
        }
        if(sum>=WRAP)
            sum=sum%WRAP;
    }

    return sum;
}

int main()
{

    LL n,k;

//    while(1)
    {

    scanf("%lld %lld", &n, &k);

    LL sum = calcVitaSum(n,k);

    printf("%lld\n",sum);
    }
}
