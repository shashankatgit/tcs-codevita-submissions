#include<bits/stdc++.h>

using namespace std;

int n;
int m[1000][1000];

int rookArrangements(int starr, int starc)
{
    int sum=0;

    sum+=m[starr][starc];
    m[starr][starc] = -1;

    for(int i=0; i<n; i++)
    {

        int max=0;



    }
    return sum;

}

void show()
{
    for(int i=0;i<n;i++)
    {

        for(int j=0;j<n;j++)
        {
            cout<<m[i][j]<<",";
        }
        cout<<endl;
    }
}

int main()
{
    cin>>n;

    int sr, sc;
    scanf("%d,%d", &sr, &sc);

    for(int i=0;i<n;i++)
    {
        scanf("%d", &m[i][0]);
        for(int j=1;j<n;j++)
        {
            scanf(",%d", &m[i][j]);
        }
    }

    //show();

    int sum = rookArrangements(sr, sc);
    cout<<sum;
}
