
#include<bits/stdc++.h>

#define LL long long

using namespace std;


int maskHexModulo = 15;
//return last digit of the subfunction
int calcFunc(short temp1, LL n)
{
    LL j;
    LL temp2,sumTemp;
    short ldigit=0,termLDigit,op1Ldigit,op2Ldigit;

    op1Ldigit = temp1;
    op2Ldigit = 1;

    for(j=0;j<=n;j++)
    {
        ldigit+=op1Ldigit*op2Ldigit;
        op2Ldigit=(op2Ldigit<<2)%10;
    }

    return ldigit%10;
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

    printf("value of i is %lld and 2^i is %lld\n", powerAliasI, temp);

    ldigit=0;
    short term1 = 1;
    for(i=0;i<=temp;i++)
    {
        ldigit += calcFunc(term1,n);
        ldigit = ldigit%10;
        term1=(term1<<2)%10;
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
