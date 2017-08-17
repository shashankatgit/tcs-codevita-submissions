#include<stdio.h>
#include<ctype.h>

#define WHITE 0
#define BLACK 1

void convert(int i, int j, char *str){

    str[0]='a'+j;
    str[1]='8'-i;
    str[2]='\0';

}

int check(char a, char turn[])
{
    int flag=0;
    if(!isdigit(a))
        {
        if(isupper(a) && turn[0]=='b')
            flag=1;

        else if(islower(a) && turn[0]=='w')
            flag=1;

        else flag=0;

        }

    //printf("a= %d flag = %d\n turn=%c",a, flag, turn[0]);

    return flag;

}

void populate(char exp[],int m[][8])
{
    int i,j,k,t;

    i=0;
    j=0;
    k=0;


    while(exp[k]!='\0')
    {
        //printf("%d %d, ",i,j);
        if(exp[k]=='/') {
            k++;
            i++;
            j=0;
            continue;
        }

        else if(isdigit(exp[k])){
            int x= exp[k] - '0';
            for(t=0;t<x;t++)
                m[i][j++]='0';

            k++;
        }

        else{
            m[i][j++] = exp[k++];
        }
    }
}


int main()
{
 char exp[75];
 char finalStr[1000];
 unsigned countFinal=0;
 char tempstr[5];
 unsigned int i,j;
 char turn[2];
 int searchfor;

 int param;

 scanf("%s",exp);
 scanf("%s",turn);

 if(turn[0] == 'b')
    {
    searchfor='p';
    param = +1;
    }
 else
    {
    searchfor='P';
    param = -1;
    }

 int m[8][8];
 populate(exp,m);

 /*
 for(i=0;i<8;i++)
 {
    for(j=0;j<8;j++)
        printf("%c ",m[i][j]);
    printf("\n");
 }*/

 //printf("Unit = %c",m[5][1]);

 finalStr[countFinal++]='[';
 for(j=0;j<8;j++)
 {
    for(i=0;i<8;i++)
    {
        if(m[i][j]==searchfor)
        {
            //printf("%d %d\n",i,j);
            //convert(i,j,tempstr);
            //printf("pos = %s\n", tempstr);
            if((i==1 && param>0) || (i==6 && param<0))
            {
                if(countFinal!=1)
                    {
                    finalStr[countFinal++]=',';
                    finalStr[countFinal++]=' ';
                    }
                convert(i,j,tempstr);
                finalStr[countFinal++]=tempstr[0];
                finalStr[countFinal++]=tempstr[1];

                convert(i+param*2, j, tempstr);
                finalStr[countFinal++]=tempstr[0];
                finalStr[countFinal++]=tempstr[1];
            }

        else{
            if(j>0 && ((i<7 && param>0) || (i>0 && param<1))&& check(m[i+param][j-1], turn))
            {
                if(countFinal!=1)
                    {
                    finalStr[countFinal++]=',';
                    finalStr[countFinal++]=' ';
                    }
                convert(i,j,tempstr);
                finalStr[countFinal++]=tempstr[0];
                finalStr[countFinal++]=tempstr[1];

                convert(i+param, j-1, tempstr);
                finalStr[countFinal++]=tempstr[0];
                finalStr[countFinal++]=tempstr[1];
            }


            if( ((i<7 && param>0) || (i>0 && param<1)) && m[i+param][j]=='0' )
            {
                if(countFinal!=1)
                    {
                    finalStr[countFinal++]=',';
                    finalStr[countFinal++]=' ';
                    }
                convert(i,j,tempstr);
                finalStr[countFinal++]=tempstr[0];
                finalStr[countFinal++]=tempstr[1];

                convert(i+param, j, tempstr);
                finalStr[countFinal++]=tempstr[0];
                finalStr[countFinal++]=tempstr[1];
            }

            if( j<7 && ((i<7 && param>0) || (i>0 && param<0)) && check(m[i+param][j+1], turn))
            {
                if(countFinal!=1)
                    {
                    finalStr[countFinal++]=',';
                    finalStr[countFinal++]=' ';
                    }
                convert(i,j,tempstr);
                finalStr[countFinal++]=tempstr[0];
                finalStr[countFinal++]=tempstr[1];

                convert(i+param, j+1, tempstr);
                finalStr[countFinal++]=tempstr[0];
                finalStr[countFinal++]=tempstr[1];
            }

            }
        }
    }

 }

 finalStr[countFinal++]=']';
 finalStr[countFinal++]='\0';

 printf("%s",finalStr);


 return 0;
}
