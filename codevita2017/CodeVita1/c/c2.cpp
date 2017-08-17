#include<bits/stdc++.h>

using namespace std;

char p[15][100];

void makeP(string s, int depth)
{
    int strPt=0;
    int curDepth=0;
    int cPos = 0;

    while(strPt<s.length())
    {
        int i,j,tmp;

        if(curDepth!=depth-1)
        {

            for(i=0; i<curDepth; i++)
            {
                cPos++;
            }

            p[curDepth][cPos] = s[strPt++]; //1st
            //cout<<endl<<s[strPt];

            tmp = 2*(depth-curDepth)-3;
            for(i=0;i<=tmp;i++)
            {
                cPos++;
            }

            p[curDepth][cPos] = s[strPt++]; //2nd

            if(curDepth!=0)
            {
                tmp=2*curDepth - 1;
                for(i=0;i<=tmp;i++)
                {
                    cPos++;
                }
                p[curDepth][cPos] = s[strPt++]; //3rd from 1st depth onward
            }

            tmp = 2*(depth-curDepth)-3;
            for(i=0;i<=tmp;i++)
            {
                cPos++;
            }

            p[curDepth][cPos] = s[strPt++];
            curDepth++;
            cPos=0;
        }

        else
        {
            for(i=0; i<curDepth; i++)
            {
                cPos++;
            }

            p[curDepth][cPos] = s[strPt++];

            tmp = 2*depth-3;
            for(i=0;i<=tmp;i++)
            {
                cPos++;
            }
            p[curDepth][cPos] = s[strPt++];

            curDepth++;
            cPos=0;
        }
    }

}

void printAns(int depth, int len)
{
    int flag=1;
    char c;
    for(int i=0;i<depth && flag;i++)
        {
            c=p[i][i];
            if(c=='X')
                flag=0;
            else
                cout<<c;
        }
    for(int i=1;i<depth && flag;i++)
        {
            c=p[depth-i-1][depth+i-1];
            if(c=='X')
                flag=0;
            else
                cout<<c;
        }

    for(int i=1;i<depth && flag;i++)
        {
            c=p[i][2*depth+i-2];
            if(c=='X')
                flag=0;
            else
                cout<<c;
        }
    for(int i=1; i<depth && flag;i++)
    {
        c=p[depth-i-1][3*depth-3+i];
        if(c=='X')
                flag=0;
            else
                cout<<c;

    }
}

void show(int depth, int len)
{
    for(int i=0;i<depth;i++)
    {
        for(int j=0;j<len;j++)
        {
            cout<<p[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

void init(int depth, int len)
{
    for(int i=0;i<=depth;i++)
    {
        for(int j=0;j<=len;j++)
        {
            p[i][j]='X';
        }
    }
}
int main()
{
    string s;
    int depth;

    cin>>depth;
    cin>>s;

    //cout<<s<<endl;

    int len = s.length();
    init(depth, len);
    makeP(s, depth);
    show(depth, len);

    printAns(depth, len);

}

