#include<bits/stdc++.h>
#define MAX 40;

using namespace std;

int pond[20][20];
int visited[20][20]={0};

int n;
int desR, desC, srcR, srcC;
int dist[20][20];

int minim(int a, int b, int c, int d) {
    int m = a;

    if(m>b)
        m=b;
    if(m>c)
        m=b;
    if(m>d)
        m=d;
}

void f(int curR, int curC)
{
    int flag;

    if(srcC==curC &&  srcR==curR)
    {
        //cout<<"Destination"<<endl;
        return;
    }

    //cout<<"At "<<curR<<", "<<curC<<endl;

    int k;
    //left
    flag=0;

    for(k=curC-1; k>=0; k--)
    {
        if(pond[curR][k]==1)
        {
            flag=1;
            if(dist[curR][k]> dist[curR][curC]+1)
                {
                    dist[curR][k] = dist[curR][curC]+1;
                    f(curR, k);
                }
            break;
        }
    }

    //right
    flag=0;
    for(k=curC+1; k<n; k++)
    {
        if(pond[curR][k]==1)
        {
            flag=1;
            if(dist[curR][k]> dist[curR][curC]+1)
                {
                    dist[curR][k] = dist[curR][curC]+1;
                    f(curR, k);
                }

            break;
        }
    }

    //up
    flag=0;
    for(k=curR-1; k>=0; k--)
    {
        if(pond[k][curC]==1)
        {
            flag=1;
            if(dist[k][curC]> dist[curR][curC]+1)
            {
                dist[k][curC] = dist[curR][curC]+1;
                f(k, curC);
            }

            break;
        }
    }

    //down
    flag=0;
    for(k=curR+1; k<n; k++)
    {
        if(pond[k][curC]==1)
        {
            flag=1;
            //cout<<dist[k][curC]<<" ";
            if(dist[k][curC]> dist[curR][curC]+1)
            {
                dist[k][curC] = dist[curR][curC]+1;
                f(k, curC);
            }

            //cout<<"failed";

            break;
        }
    }



}



void showPond()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main()
{

    cin>>n;

    for(int i=0;i<n;i++)
    {
        scanf("%d",&pond[i][0]);
        for(int j=1;j<n;j++)
        {
            scanf(",%d",&pond[i][j]);
        }
    }

    //showPond();


    scanf("%d,%d", &srcR, &srcC);
    scanf("%d,%d", &desR, &desC);
    desR-=1;
    desC-=1;
    srcC-=1;
    srcR-=1;
    //cout<<"Dest is "<<desR<<", "<<desC<<endl;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            dist[i][j]=MAX;
        }
    }

    dist[desR][desC]=0;

    //showPond();
    f(desR, desC);

    //showPond();
    cout<<dist[srcC][srcR];

}
