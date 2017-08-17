#include<bits/stdc++.h>

using namespace std;

string pond;
int len;
map<char, string> rel;

int dp[100];

int jumpsTo(int n)
{
    char c=pond[n];
    //cout<<"\n\n";
    //cout<<"tile num = "<<n<<", color = "<<c<<endl;

    if(n==0)
        return 1;

    if(dp[n]!=-1)
        return dp[n];


    int ways=0;
    int flag=0;
    for(int i=0; i<3; i++)
    {
        char cprev = rel[c][i];
        for(int j=n-1;j>=0;j--)
        {
            if(pond[j]==cprev)
            {
                //cout<<"jump from "<<j<<endl;
                ways+= jumpsTo(j);
                flag=1;

            }

            if(pond[j]==c)
                break;
        }

    }

    //if(flag==0)
        //cout<<"dead end reached"<<endl;
    dp[n]=ways;
    return ways;


}

void init()
{

    rel['R']="RYO";
    rel['G']="GYB";
    rel['Y']="YRO";
    rel['B']="BGR";
    rel['O']="OBG";

    for(int i=0;i<100;i++)
        dp[i]=-1;

}
int main()
{
    init();

    getline(cin, pond);

    int ways=0;

    for(int i=1;i<6;i++)
        ways+=jumpsTo(pond.size()-i);

    cout<<ways;
}
