
#include<bits/stdc++.h>

using namespace std;

struct point{
    int x,y;
};


void spiralTraversalMod11(int n)
{
    int metric=n;
    int i,j;
    int sq = n*n;
    int count = 1;
    unsigned movLeft=0,movRight=1,movUp=0,movDown=0;

    i=0;j=0;
    int matrix[n][n];

    int entries[10000][2],entry_count=0;



    entries[entry_count][0]=0;
    entries[entry_count++][1]=0;
    while(count<=sq)
    {
        matrix[i][j]=count;
        if(count%11==0)
        {
            entries[entry_count][0]=i;
            entries[entry_count++][1]=j;

        }

//    printf("count=%d,i=%d,j=%d\n",count,i,j);

        if(movRight)
        {
            ++j;
            ++count;
            if(j==metric)
            {
                --j;
                ++i;
                movRight=0;
                movDown=1;
            }
        }

        else if(movDown)
        {
            ++i;
            ++count;
            if(i==metric)
            {
                --i;
                --j;
                movDown=0;
                movLeft=1;
            }
        }

        else if(movLeft)
        {
            --j;
            ++count;
            if(j==(n-metric))
            {
                movLeft=0;
                movUp=1;
            }
        }

        else if(movUp)
        {
            --i;
            ++count;
            if(i==(n-metric))
            {
                ++i;
                ++j;
                movUp=0;
                movRight=1;
                metric-=1;
            }
        }

    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            printf("%d ",matrix[i][j]);

        printf("\n");
    }

    printf("Total Power points : %d\n",entry_count);
    for(i=0;i<entry_count;i++)
    {
        printf("(%d,%d)\n",entries[i][0],entries[i][1]);
    }
}


int main()
{
    int n;

    scanf("%d",&n);

    spiralTraversalMod11(n);

    return 0;
}
