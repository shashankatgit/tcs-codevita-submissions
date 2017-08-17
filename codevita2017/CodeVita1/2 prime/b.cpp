#include<bits/stdc++.h>

using namespace std;

int primes[1000];

int isPrime(int n)
{
    int flag=1;
    int sq = sqrt(n);
    for(int i=2; i<=sq; i++)
    {
        if(n%i == 0)
            {
                flag = 0;
                break;
            }
    }

    if(flag == 1)
        return 1;

    else
        return 0;
}

int main()
{
    int n;
    cin>>n;

    int ptr=0;

    primes[0]=2;
    int a=1;
    int sq = sqrt(n);
    for(int i=3;i<=n;i++)
    {
        if(isPrime(i))
        {
            primes[a++]=i;
        }
    }

    ptr=a;

    //cout<<"last prime = "<<primes[ptr-1]<<endl;
    int count=0;
    int n1,n2;
    for(int i=0;i<ptr;i++)
    {
        for(int j=i;j<ptr;j++)
        {
            if(primes[j]<10)
                n1 = primes[i]*10 + primes[j];
            else
                n1 = primes[i]*100 + primes[j];

            if(primes[i]<10)
                n2 = primes[j]*10 + primes[i];
            else
                n2 = primes[j]*100 + primes[i];

            if(isPrime(n1))
                {
                    count++;
                    //cout<<primes[i]<<" "<<primes[j]<<" "<<n1<<endl;
                }
            if(isPrime(n2))
            {
                   count++;
                   //cout<<primes[j]<<" "<<primes[i]<<" "<<n2<<endl;
            }
        }
    }

    cout<<count;

}

