#include<bits/stdc++.h>

using namespace std;

int isBalanced(string str)
{
    int len = str.length();
    char s[100001];
    int cnt=0;

    int skip=0;

    for(int i=0;i<len;i++)
    {
        //cout<<endl<<str[i];
        if(i<len-1 && str[i]=='@' && str[i+1]=='*') //comment
            {
                skip = 1;
                continue;
            }

        else if(i>0 && str[i-1]=='*' && str[i]=='@')
            {
                skip = 0;
                continue;
            }

        else if(!skip)
        {
            s[cnt++] = str[i];
        }
    }

    if(skip)
        return 0;

    s[cnt]='\0';

    stack<char> st;

    //cout<<"Cnt = "<<cnt<<" and Filtered string is "<<s<<endl;

    for(int i = 0; i<cnt; i++)
    {
        char c = s[i];

        if(c=='(' || c=='{' || c=='<' || c=='[' || c=='/')
                    {
                        st.push(c);
                    }

        else if(c==')' || c=='}' || c=='>' || c==']' || c=='\\')
                    {
                        if(!st.empty())
                        {
                            char tmp = st.top();
                            st.pop();

                            if(tmp=='(' && c==')')
                                continue;
                            else if(tmp=='{' && c=='}')
                                continue;
                            else if(tmp=='<' && c=='>')
                                continue;
                            else if(tmp=='[' && c==']')
                                continue;
                            else if(tmp=='/' && c=='\\')
                                continue;

                            else
                            {
                                return 0;
                            }
                        }

                        else
                        {
                            return 0;
                        }

            }
    }

    if(st.empty())
        return 1;
    else
        return 0;

}


#define NORMAL 0
#define C_BEG 1
#define C_IGNORE 2
#define C_END 3


int isBalancedS()
{
    int state=NORMAL;
    char c;
    char tmp;

    stack<char> s;

    int flag=1;
    while((c=getchar())!='\r' || c!='\n')
    {

        //cout<<endl<<"STATE = "<<state<<endl;
        if(c=='@' && state==NORMAL)
        {
            state=C_BEG;
        }
        else if(c=='*' && state==C_BEG)
        {
            state=C_IGNORE;
            //cout<<"Started ignoring"<<endl;
        }

        else if(c=='*' && state==C_IGNORE)
            state=C_END;
        else if(c=='@' && state==C_END)
        {
            state=NORMAL;
            //cout<<"Started accepting"<<endl;
        }
        else if(state==C_IGNORE)
            continue;



        else if(c=='(' || c=='{' || c=='<' || c=='[' || c=='/')
                    {
                        s.push(c);
                    }

        else if(c==')' || c=='}' || c=='>' || c==']' || c=='\\')
                    {
                        if(!s.empty())
                        {
                            tmp = s.top();
                            s.pop();

                            if(tmp=='(' && c==')')
                                continue;
                            else if(tmp=='{' && c=='}')
                                continue;
                            else if(tmp=='<' && c=='>')
                                continue;
                            else if(tmp=='[' && c==']')
                                continue;
                            else if(tmp=='/' && c=='\\')
                                continue;

                            else
                            {
                                flag=0;
                                return 0;
                            }

                        }

                        //if stack empty
                        else
                        {
                            flag=0;
                            return 0;
                        }
                    }

    }

    if(s.empty())
        return 1;

    else
        return 0;


}

int main()
{
    int t;
    cin>>t;
    cin.ignore();

    string str;
    while(t--)
    {

        getline (cin,str);
        //cout<<"string is "<<str;

        int flag = isBalanced(str);

        if(flag)
            cout<<"True\n";
        else
            cout<<"False\n";
    }


    return 0;
}
