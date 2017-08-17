#include<bits/stdc++.h>
#define MAX 40;

int mod = 1000000007
int powmod(int base,int pow)
{
   int res=1;
   while(pow)
   {
         if (pow%2!=0)  res=(res*base)%mod;
         base=(base*base)%mod;
         pow/=2;
   }
   return res;
}
