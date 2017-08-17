#include<bits/stdc++.h>

using namespace std;

//int nextPos(int curPos, int depth)
//{
//    curPos++;
//    int nextPos;
//    int eqPos = curPos % (2*depth);
//    {
//        if(eqPos==1)
//        {
//            nextPos = (curPos+2*depth-2;
//        }
//
//        if(eqPos==depth)
//        {
//
//        }
//    }
//}

int numW(int depth, int slen)
{
    int count=1;

    slen-= 4*depth-3;

    int tmp = depth-1;
    while(slen>0)
    {
        slen/= (4*tmp);
        count++;
    }

    cout<<"no of W = "<<count;
    return count;
}

int main()
{
    string s;
    int depth;

    cin>>depth;
    getline(cin, s);

    cout<<s<<endl;

    int len = s.length();
    int cur = 0;
    int next;

    for(int c=0; c < len; c++)
    {
        if(cur)
    }

}
