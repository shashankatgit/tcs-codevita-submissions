
#include<bits/stdc++.h>

using namespace std;

int verify(char *input)
{
    stack<char> symbolStack;

    int i;
    int valid=1;
    int keyAcceptance=0;
    int arrayAcceptance=0;
    int commaAcceptance=0;
    int objectAcceptance=1;
    int arrayEmpty=1;

    for(i=0;input[i]!='\0' && valid==1;i++)
    {

        char c=input[i];
//        printf("processed %c at %d\n",c, i);
        switch(c)
        {
            case '{':
                        if(!objectAcceptance)
                        {
                            valid=0;
                            break;
//                            printf("rejected due to %c at %d\n",c,i);
                        }
                        keyAcceptance=1;
                        commaAcceptance=1;
                        symbolStack.push('{');
                        break;

            case ':':
                        if(!keyAcceptance)
                        {
                            valid=0;
                            break;
//                            printf("rejected due to %c at %d\n",c,i);
                        }
                        keyAcceptance=0;
                        objectAcceptance=1;
                        arrayAcceptance=1;
                        commaAcceptance=1;
                        break;

            case '[':
                        if(!arrayAcceptance)
                        {
                            valid=0;
                            break;
//                            printf("rejected due to %c at %d\n",c,i);
                        }
                        symbolStack.push('[');
                        keyAcceptance=0;
                        objectAcceptance=1;
                        arrayAcceptance=0;
                        commaAcceptance=0;
                        arrayEmpty=1;
                        break;
            case ',':
                        if(!commaAcceptance)
                        {
                            valid=0;
                            break;
//                            printf("rejected due to %c at %d\n",c,i);
                        }

                        keyAcceptance=1;
                        commaAcceptance=0;
                        objectAcceptance=1;
                        break;

            case ']':
                        if(symbolStack.top()!='[' || arrayEmpty==1)
                        {
                            valid=0;
                            break;
//                            printf("rejected due to %c at %d \n",c,i);
                        }
                        symbolStack.pop();
                        commaAcceptance=1;
                        break;

            case '}':
                        if(symbolStack.top()!='{')
                        {
                            valid=0;
                            break;
//                            printf("rejected due to %c at %d\n",c,i);
                        }
                        symbolStack.pop();

                        if(!symbolStack.empty() && symbolStack.top()=='[')
                            arrayEmpty=0;

                        if(!symbolStack.empty())
                            commaAcceptance=1;
                        else
                            commaAcceptance=0;
                        break;

            default:
                        valid=0;
                        break;

        }
    }

    if(!symbolStack.empty())
        valid=0;

    if(valid)   return 1;
    else        return -1;

}

int main()
{
    char input[10000];

//    while(1)
    {

    scanf("%s",input);

    int status = verify(input);
    printf("%d",status);
    }
}
