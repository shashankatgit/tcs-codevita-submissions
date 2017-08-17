
#include<bits/stdc++.h>

using namespace std;


int a1[1000];
int a2[1000];


int calcCost(int n, int base)
{
    if(n%2==1) //odd
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

        show(a1, n);
        show(a2, n);
    }

    else //even
    {
        for(int i=1;i<n/2;i++)
        {
            if(a2[i]<=a2[i-1])
            {
                a2[i]=a2[i-1]+1;
            }
        }

        for(int i=n-2; i>=n/2; i++)
        {
            if(a2[i]<=a2[i+1])
            {
                a2[i]=a2[i+1]+1;
            }
        }

        if(a2[n/2]>a2[n/2-1])
            a2[n/2-1] = a[n/2];
        else
            a2[n/2] = a[n/2-1];

        for(int i=n/2-2;i>=0; i--)
        {
            a2[i] = a[i+1]-1;
        }

        for(int i=n/2+1;i<n; i++)
        {
            a2[i] = a[i-1]-1;
        }

        show(a1, n);
        show(a2, n);
    }


}


void show(int *a, int n)
{
   for(int j=0;j<n;j++)
        {
            cout<<a[j]<<",";
        }
    cout<<endl;
}

int main()
{
    int n;
    int base;
    int t;
    int cost;

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

        cout<<cost;
    }

}
