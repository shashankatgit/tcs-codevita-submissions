
#include<bits/stdc++.h>

using namespace std;

int n;
int m[20][20];

void show()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0; j<n;j++ )
            cout<<m[i][j];

        cout<<endl;
    }
}

void infect(int ir, int ic, int level)
{
    if(ir<0 || ic<0 || ir>=n || ic>=n || m[ir][ic]==0)
        return;

    //cout<<ir<<ic<<endl;

    if(type==1)
    {

        infect(ir-1, ic-1, level, type-1);
        infect(ir-1, ic, level, type-1);
        infect(ir-1, ic+1, level, type-1);

        infect(ir, ic-1, level, type-1);
        m[ir][ic] = level;
        infect(ir, ic+1, level, type-1);

        infect(ir+1, ic-1, level, type-1);
        infect(ir+1, ic, level, type-1);
        infect(ir+1, ic+1, level, type-1);


    }

    else
    {
        if(m[ir][ic]<level)
        {
            m[ir][ic] = level;

            level-=1;

            if(level>1)
            {

                infect(ir-1, ic-1, level, 0);
                infect(ir-1, ic, level, 0);
                infect(ir-1, ic+1, level, 0);

                infect(ir, ic-1, level, 0);
                infect(ir, ic+1, level, 0);

                infect(ir+1, ic-1, level, 0);
                infect(ir+1, ic, level, 0);
                infect(ir+1, ic+1, level, 0);
            }
        }

    return;
    }
}

void dinfect(int ir, int ic, int type)
{
    if(ir<0 || ic<0 || ir>=n || ic>=n || m[ir][ic]==0)
        return;

    //cout<<ir<<ic<<endl;

    if(type==1)
    {

        dinfect(ir-1, ic-1, level, type-1);
        dinfect(ir-1, ic, level, type-1);
        dinfect(ir-1, ic+1, level, type-1);

        dinfect(ir, ic-1, level, type-1);
        m[ir][ic] = 1;
        dinfect(ir, ic+1, level, type-1);

        dinfect(ir+1, ic-1, level, type-1);
        dinfect(ir+1, ic, level, type-1);
        dinfect(ir+1, ic+1, level, type-1);


    }

    else
    {
        if(m[ir][ic]<level)
        {
            m[ir][ic] = level;

            level-=1;

            if(level>1)
            {

                dinfect(ir-1, ic-1, level, 0);
                dinfect(ir-1, ic, level, 0);
                dinfect(ir-1, ic+1, level, 0);

                dinfect(ir, ic-1, level, 0);
                dinfect(ir, ic+1, level, 0);

                dinfect(ir+1, ic-1, level, 0);
                dinfect(ir+1, ic, level, 0);
                dinfect(ir+1, ic+1, level, 0);
            }
        }

    return;
    }
}

int main()
{
    cin>>n;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d", &m[i][j]);
        }
    }


    int infr, infc, antir, antic;
    cin>>infr>>infc;
    cin>>antir>>antic;

    show();

    //infecting
    infr--;
    infc--;
    antir--;
    antic--;

    infect(infr, infc, 5, 1);

    dinfect(antir, antic, 4, 1);

    show();

}
