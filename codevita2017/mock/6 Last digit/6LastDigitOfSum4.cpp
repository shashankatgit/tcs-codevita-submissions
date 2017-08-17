
#include<bits/stdc++.h>

#define LL long long

using namespace std;


int maskHexModulo = 15;
//return last digit of the subfunction
int calcFuncSum(LL n)
{
    LL  termLDigit = 4;
    LL power=n+1;

//    while(power > 4)
//    {
//
//            printf("even power");
//            power--=4;
//            termLDigit=(termLDigit<<4)%10;
//    }

    termLDigit=((termLDigit<<n)%31-1)/3;
    return termLDigit%10;

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

    //printf("value of i is %lld and 2^i is %lld\n", powerAliasI, temp);

    ldigit=0;
    short term1LDigit = 1;
    short term2LDigit  = calcFuncSum(n);
    LL factor=1;
    for(i=0;i<=temp;i++)
    {
        factor=factor<<2;
        term1LDigit+= (1<<factor)%10;
    }


    return (term1LDigit*term2LDigit)%10;


}



int main()
{
    LL n;

    scanf("%lld",&n);

    int last=0;
    last= calcLastDigit(n);

    printf("%d",last);

    return 0;
}
