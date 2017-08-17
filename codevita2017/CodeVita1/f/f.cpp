#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    string seq;

    cin>>n;
    cin.ignore();

    for(int i=0;i<n;i++)
    {
        stack<int> stacks[26];
        int stackCnt=1;

        getline(cin, seq);

        stacks[0].push(seq[0]);

        for(int j=2; seq[j-1]; j+=2)
        {
            char c=seq[j];
            int ok=0;
            int k;
            for(k=0; k<stackCnt; k++)
            {
                if(stacks[k].top() >= c)
                {
                    ok=1;
                    break;
                }
            }

            if(ok==1)
            {
                stacks[k].push(c);
            }
            else
            {
                stacks[stackCnt].push(c);
                stackCnt++;
            }

        }

    cout<<stackCnt<<endl;

    }
}
