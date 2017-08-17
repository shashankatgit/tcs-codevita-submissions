#include<stdio.h>
    int sqMap[50][2];
    int cuMap[50][2];
    int sqCount=0;
    int cuCount=0;
    int hiSq=0;
    int hiCu=0;

int isJsonAr(char str[], int b)
{
    int flag=0;
    if(str[1]=='{')

}

int main()
{
    int inObjState=0;
    int inArrayState=0;

    int curlyCount=0;
    int squareCount = 0;

    int count=0;

    char str[1000];



    int flag=0;

    int i;

    scanf("%s",str);

    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]=='{')
        {
             ++curlyCount;
             cuMap[cuCount++][0]=i;
             hiCu++;
        }
        else if(str[i]=='[')
        {
            ++squareCount;
            sqMap[sqCount++][0]=i;
            hiSq++;
        }
        else if(str[i]=='}')
        {
            --curlyCount;
            if(curlyCount>=0)
                cuMap[--cuCount][1]=i;

        }
        else if(str[i]==']')
        {
            --squareCount;
            if(squareCount>=0)
                sqMap[--sqCount][1]=i;
        }
    }

    if(curlyCount==0 && squareCount==0)
    {
        /*for(i=0;i<hiSq;i++)
            printf("%d %d\n",sqMap[i][0],sqMap[i][1]);

            printf("here"); */



    }

    else
    {
        flag=0;
    }

    if(flag==0)
        printf("-1");
    else printf("1");

}
