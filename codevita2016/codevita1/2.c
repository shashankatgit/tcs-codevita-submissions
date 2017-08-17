#include<stdio.h>
#include<math.h>

int main()
{

 double p, r, amt, flow;
 int t;
 double tmp1,tmp2;
 double amount,interest;
 int n,i;

    scanf("%lf %d %lf",&flow,&t, &r);

    amt=flow*t;

    tmp1 = pow(1.0+r/1200.0, t);

    //printf("%lf\n",tmp1);

    p = amt/tmp1;

    amount=0;
    interest=0;
    for(i=0;i<t;i++){
        interest=amount*r/1200;
        amount+=(interest + flow);
    }

    interest = amount - flow*t;

    amount = interest/pow(1.0+r/1200, t);

    printf("%d",(int)round(amount + p));

 return 0;
}
