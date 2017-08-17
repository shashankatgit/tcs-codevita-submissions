#include<bits/stdc++.h>
#define MAX 40;

using namespace std;

int pond[20][20];
int visited[20][20]={0};

int n;
int desR, desC;

int minim(int a, int b, int c, int d) {
    int m = a;

    if(m>b)
        m=b;
    if(m>c)
        m=b;
    if(m>d)
        m=d;
}

int f(int srcR, int srcC)
{
    if(srcC==desC &&  srcR==desR)
    {
        cout<<"Destination"<<endl;
        return 0;
    }

    if(visited[srcR][srcC]==1)
        return 40;

    cout<<"At "<<srcR<<", "<<srcC<<endl;

    if(visited[srcR][srcC]==0)
        visited[srcR][srcC]=1;

    int t1, t2, t3, t4;

    t1=t2=t3=t4=MAX;
    int flag;
    int k;

    //left
    flag=0;
    for(k=srcC-1; k>=0; k--)
    {
        if(pond[srcR][k]==1)
        {
            flag=1;
            break;
        }
    }

    if(flag==1)
        t1=f(srcR, k);

    //right
    flag=0;
    for(k=srcC+1; k<n; k++)
    {
        if(pond[srcR][k]==1)
        {
            flag=1;
            break;
        }
    }

    if(flag==1)
        t2=f(srcR, k);



    //top
    flag=0;
    for(k=srcR-1; k>=0; k--)
    {
        if(pond[k][srcC]==1)
        {
            flag=1;
            break;
        }
    }

    if(flag==1)
        t3=f(k,srcC);

    //down
    flag=0;
    for(k=srcR+1; k<n; k++)
    {
        if(pond[k][srcC]==1)
        {
            flag=1;
            break;
        }
    }

    if(flag==1)
        t4=f(k, srcC);


    cout<<"At "<<srcR<<", "<<srcC<<":"<<t1<<" "<<t2<<" "<<t3<<" "<<t4<<endl;

    //if(minim(t1,t2,t3,t4)<40)
        return minim(t1,t2,t3,t4) + 1;
    //else
        return 40;

}



void showPond()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<pond[i][j]<<" ";
        }
        cout<<endl;
    }
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
    int srcR, srcC;

    scanf("%d,%d", &srcR, &srcC);
    scanf("%d,%d", &desR, &desC);
    desR-=1;
    desC-=1;
    cout<<"Dest is "<<desR<<", "<<desC<<endl;
    cout<<f(srcR-1, srcC-1);

}
