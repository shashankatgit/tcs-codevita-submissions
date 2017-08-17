#include<stdio.h>
#include<ctype.h>

#define WHITE 0
#define BLACK 1

int populate(char exp[],int m[][8])
{
    int i,j,k,t;

    i=0;
    j=0;
    k=0;

    int spaces = 0;

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
            *spaces+=x;
            for(t=0;t<x;t++)
                m[i][j++]='0';

            k++;
        }

        else{
            m[i][j++] = exp[k++];
        }
    }
}

void showMatrix(int m[][8],int spaces){
    int i,j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++){
            printf("%c ",m[i][j]);
        }
    printf("\n");
    }
    printf("spaces : %d",spaces);
}

void convert(int i, int j, char *str){

    str[0]='a'+j;
    str[1]='8'-i;
    str[2]='\0';

}

void copyMatrix(int m1[][8],int m2[][8])
{
    int i,j;
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            m1[i][j] = m2[i][j];
}

int main()
{

 int i,j;
 int count1=0;
 int rowCount=1;
 int matrix1[8][8];
 int matrix2[8][8];

 char exp[200];
 char movStr1[10];
 char movStr2[10];

 int spaces1;
 int spaces2;
 int turn;
 int captures = 0;

 int flag;
 char row;

 scanf("%s",exp);

 //printf("chkp1");

 populate(exp, matrix1, &spaces1);

 //printf("checkp2");
 //showMatrix(matrix1, spaces1);

 //convert(8,2,movStr1);
 //printf("\n%s\n",movStr1);

 turn = WHITE;

 while(1){
    scanf("%s",exp);
    if(exp[0]=='-') break;

    populate(exp, matrix2, &spaces2);

    if((count1%2)==0) {
        printf("\n%d) ",rowCount++);
    }

    if(spaces1 == spaces2) //No capture condition
    {
        flag=0;
        for(i=0;i<8;i++){
            for(j=0;j<8;j++){

                if(matrix1[i][j]!=matrix2[i][j] && matrix1[i][j]=='0'){
                    if(matrix2[i][j]!='p' && matrix2[i][j]!='P')
                        {
                            movStr1[0]=toupper(matrix2[i][j]);
                            convert(i,j,movStr1+1);
                        }
                    else
                        {
                            convert(i,j,movStr1);
                        }
                    printf("%s ",movStr1);
                    count1++;
                    flag=1;
                    break;

                }
            }
            if(flag) break;
        }
    }

    else
    {
        captures++;
        flag=0;
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            {
                if(matrix1[i][j]!=matrix2[i][j])
                {
                    if(matrix2[i][j]=='0')
                    {
                        if(matrix1[i][j]=='p' || matrix1[i][j]=='P')
                        {
                            row = 'a'+j;
                            ++flag;
                        }
                        else
                        {
                            row = toupper(matrix1[i][j]);
                            ++flag;
                        }
                    }

                    else {
                        convert(i,j,movStr1);
                        ++flag;
                    }

                    if(flag>=2) break;
                }
                if(flag>=2) break;
            }
        }

        movStr2[0]=row;
        movStr2[1]='x';
        movStr2[2]=movStr1[0];
        movStr2[3]=movStr1[1];
        movStr2[4]='\0';

        printf("%s ",movStr2);
        count1++;
    }

    turn=!turn;
    copyMatrix(matrix1,matrix2);
    spaces1=spaces2;


 }

 printf("\nNumber of Captures : %d",captures);
 return 0;
}
