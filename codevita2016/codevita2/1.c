#include<stdio.h>

unsigned int store[10000002];

int min(int a, int b)
{
    return a>b? a:b;
}

void computeComb(unsigned int n, unsigned int k)
{

    unsigned int i,j;

    store[0]=1;

    for(i=0;i<n;i++)
    {
        for(j=i>k?i:k ; j>0; j--)
        {
            store[j] = store[j] + store[j-1];
        }
        //printf("%d, ",store[i]);
    }
    if(n!=0) store[n+1]=1;

/*
    for(i=0;i<=n;i++)
        {
            printf(" , %lld",store[i]);
        }
    return store[k];

*/
}

unsigned long int calc(unsigned k)
{
    unsigned long sum=0;
    unsigned int i;
    for(i=0;i<=k;i+=2)
        sum+=store[i];

    return sum;
}

int main()
{
    unsigned int n, k;
    memset(store,0,sizeof(store));
    scanf("%u %u",&n, &k);

    computeComb(n, n);
    printf("%ld",calc(k));


 return 0;
}
