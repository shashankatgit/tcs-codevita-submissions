
#include<bits/stdc++.h>

#define LL long long

using namespace std;


int maskHexModulo = 15;
//return last digit of the subfunction
int calcFunc(LL i, LL n)
{
    LL j;
    LL temp1,temp2,sumTemp;
    short ldigit=0,termLDigit,op1Ldigit,op2Ldigit;

    temp1 = 1<<i;
    op1Ldigit = (2<<temp1)&maskHexModulo;
    op2Ldigit = 1;

    for(j=0;j<=n;j++)
    {
        ldigit+=op1Ldigit*op2Ldigit;
        op2Ldigit=(op2Ldigit<<2)&maskHexModulo;
    }

    return ldigit&maskHexModulo;
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
        ldigit = ldigit&maskHexModulo;
    }

    if(ldigit<10)
        return ldigit;
    else
        return ldigit-10;


}



int main()
{
    LL n;

    scanf("%lld",&n);

    int last= calcLastDigit(n);

    printf("%d",last);

    return 0;
}
