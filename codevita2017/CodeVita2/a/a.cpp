#include<bits/stdc++.h>

using namespace std;

#define FMacro(x) (1000*x*x)



long long f[1001];

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

long long sumF(int base, int incr)
{
    long long sum=0;

    for(int i=0; i<incr; i++)
    {
        sum+= F(base-i);
    }

    return sum;
}

int calcCost(int *a, int n, int base)
{
    //find largest height
    int i;
    int mid = n/2;
    int largest=mid;

    long long minCost = 0;

    if(n&1) // odd length
    {
        mid = n/2;
        largest=mid;

        for(i=0;i<n;i++)
            if(a[i]>a[largest] && (abs(mid-largest)<abs(mid-i)))
                largest=i;

        int highest=a[largest];

        cout<<"Largest index is "<<largest<<endl;

        if(largest != mid)
        {
            int diff = abs(mid - largest);
            int incr = a[largest] + diff - a[mid];
            minCost+= sumF(base, incr);
            a[mid] = a[mid] + incr;
            highest = a[largest]+incr;


            cout<<"mid not largest";
        }

        for(i=0; i<mid; i++)
        {
            int incr = highest-a[i]-(mid-i);
            minCost+= sumF(base, incr);
            cout<<"incr = "<<incr<<": "<<sumF(base, incr)<<endl;
        }

        for(i=n-1; i>mid; i--)
        {
            int incr = highest-a[i]-(i-mid);
            minCost+= sumF(base, incr);
        }

        return minCost;
    }

    else //even case
    {
        mid = n/2-1;
        largest=mid;

        for(i=0;i<n;i++)
            if(a[i]>a[largest] && (abs(mid-largest)<abs(mid-i)))
                largest=i;

        int highest=a[largest];

        if(largest != mid || largest!=mid+1)
        {
            int diff = min(abs(mid - largest), abs(mid+1 - largest);
            int incr = a[largest] + diff - a[mid];
            minCost+= sumF(base, incr);
            a[mid] = a[mid] + incr;

            incr = a[mid]-a[mid];

            highest = a[largest]+incr;


        }

    }




}

void showArr(int a[], int n)
{
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}


int main()
{
    int a[1000];
    int n;
    int base;
    int t;
    int cost;

    cout<<sumF(0,2);

    //cin>>t;

    //while(t--)
    {
        memset(f, 0, 1001);
        cin>>n;
        cin>>base;

        for(int i=0;i<n;i++)
            cin>>a[i];

        cost=calcCost(a, n, base);

        cout<<cost;
    }

}
