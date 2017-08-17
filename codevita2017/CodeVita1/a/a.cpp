#include<bits/stdc++.h>

using namespace std;

long long int mod = 1000000007;
long long int powmod(long long int base,long long int pow)
{
   long long int res=1;
   while(pow)
   {
         if (pow%2!=0)
            res=(res<<1)%mod;
         base=(base<<2)%mod;
         pow/=2;
   }
   return res;
}


long long int powmod2(long long int base,long long int pow)
{
   long long int res=1;
   while(pow)
   {
         if (pow%2!=0)  res=(res*base)%mod;
         base=(base*base)%mod;
         pow/=2;
   }
   return res;
}


int main(){

    int n;

    cin>>n;

    long long int ans = (powmod2(2,n-1)-2)%mod;

    if(ans<0)
        ans = 0;
    cout<<ans;
}
