
#include<bits/stdc++.h>

#define LL long long

using namespace std;



//return last digit of the subfunction
int calcFunc(LL i, LL n)
{
    LL j;
    LL temp1,temp2,sumTemp;
    int ldigit=0,termLDigit;

    temp1 = 1<<i;
    op1Ldigit = (2<<temp1)%10;

    for(j=0;j<=n;j++)
    {
        temp2 = 2*j;

        termLDigit=1;
        sumTemp=temp1+temp2;

        while(sumTemp>0)
        {
            if(sumTemp&1 == 0 )
            {
                printf("sumTemp is even\n");
                termLDigit=termLDigit<<(sumTemp/2);
                sumTemp/=2;
            }

            else
            {
                termLDigit=termLDigit<<1;
                --sumTemp;
            }

            termLDigit=termLDigit%10;
        }

        ldigit=(ldigit+termLDigit)%10;

    }

    return ldigit;
}

int calcLastDigit(LL n)
{
    LL i;
    LL temp=1;
    LL powerAliasI=0;
    int ldigit;

    //calculating upper limit 2^i less than equal to n

    while(temp<=n)
    {
        temp = temp<<1;
        powerAliasI++;
    }
    --powerAliasI;
    temp=temp/2;

    //printf("value of i is %lld and 2^i is %lld\n", power, temp);

    ldigit=0;
    for(i=0;i<=temp;i++)
    {
        ldigit += calcFunc(i,n);
        ldigit = ldigit%10;
    }

    return ldigit;


}



int main()
{
    LL n;

    scanf("%lld",&n);

    int last= calcLastDigit(n);

    printf("%d",last);

    return 0;
}
