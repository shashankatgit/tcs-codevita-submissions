
#include<bits/stdc++.h>

using namespace std;



void process(char *str)
{
    int store[57];
    int storeCount=0;
    int toggle=0;

    int calc;

    int i,j;
    char c;
    for(i=0;str[i];i++)
    {
        c=str[i];
        if(c==' ')
        {
            printf("\n");
            toggle=0;
            continue;
        }

        calc = c-64;

        if(toggle==0)
            for(j=0;j<calc;j++)
                {
                    printf("0");
                }

        else
            for(j=0;j<calc;j++)
                {
                    printf("!");
                }

        toggle=1-toggle;
    }
}

int main()
{
    char str[100000];

    fgets (str, 100000, stdin);

    process(str);
}
