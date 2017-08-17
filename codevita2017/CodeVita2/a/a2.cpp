
#include<bits/stdc++.h>

using namespace std;

#define FMacro(x) (1000*x*x)

long long f[1001];

int a1[1000];
int a2[1000];

void show(int a[], int n)
{
   for(int j=0;j<n;j++)
        {
            cout<<a[j]<<",";
        }
    cout<<endl;
}

long long F(int val)
{
    if(val<=0)
        return 1000;

    if(f[val]>0)
        return f[val];

    long long c;

    c=FMacro(val);

    f[val]=c;
    return c;
}


long long sumF(long long base, int incr)
{
    long long sum=0;

    for(int i=0; i<incr; i++)
    {
        sum+= F(base-i);
    }

    return sum;
}

long long calcCost(int n, int base)
{
    long long cost=0;
    if(n%2==1) //if n is odd
    {
        for(int i=1;i<=n/2;i++)
        {
            if(a2[i]<=a2[i-1])
            {
                a2[i]=a2[i-1]+1;
            }
        }

        for(int i=n-2; i>=n/2; i--)
        {
            if(a2[i]<=a2[i+1])
            {
                a2[i]=a2[i+1]+1;
            }
        }

        //balancing heights
        for(int i=n/2-1;i>=0; i--)
        {
            a2[i] = a2[i+1]-1;
        }

        for(int i=n/2+1;i<n; i++)
        {
            a2[i] = a2[i-1]-1;
        }

        //show(a1, n);
        //show(a2, n);
    }

    else //if n is even
    {
        for(int i=1;i<n/2;i++)
        {
            if(a2[i]<=a2[i-1])
            {
                a2[i]=a2[i-1]+1;
            }
        }

        for(int i=n-2; i>=n/2; i--)
        {
            if(a2[i]<=a2[i+1])
            {
                a2[i]=a2[i+1]+1;
            }
        }

        if(a2[n/2]>a2[n/2-1])
            a2[n/2-1] = a2[n/2];
        else
            a2[n/2] = a2[n/2-1];

        for(int i=n/2-2;i>=0; i--)
        {
            a2[i] = a2[i+1]-1;
        }

        for(int i=n/2+1;i<n; i++)
        {
            a2[i] = a2[i-1]-1;
        }

        //show(a1, n);
        //show(a2, n);
    }

    //calculating costs of increments
    for(int i=0; i<n; i++)
    {
        cost+= sumF(base, a2[i]-a1[i]);
    }
    return cost;
}




int main()
{
    int n;
    int base;
    int t;
    long long cost;

    //cout<<sumF(0,2);

    cin>>t;

    while(t--)
    {
        cin>>n;
        cin>>base;

        for(int i=0;i<n;i++)
            {
                cin>>a1[i];
                a2[i]=a1[i];
            }

        cost=calcCost(n, base);

        cout<<cost<<endl;
    }

}
