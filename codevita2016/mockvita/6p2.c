
#include<stdio.h>
#include<limits.h>

#define NUM 4
int sizes[]={1,5,7,10};

int findMinB(int amt) {
    int i,j,temp;

    int values[amt+1];
    values[0]=0;

    for(i=1;i<=amt;i++) values[i]= INT_MAX;

    for(i=1;i<=amt;i++)
    {
        for(j=0;j<NUM;j++)
        {
            if(sizes[j] <= i)
            {
                temp = values[i-sizes[j]];

                if(temp!=INT_MAX && (temp+1)<values[i])
                {
                    values[i]=temp+1;
                }
            }
        }
    }

    return values[amt];
}

int main()
{

    int amt;
    int t;
    int minN;

    scanf("%d",&t);
    while(t--){

        scanf("%d",&amt);

        minN = findMinB(amt);

        printf("%d",minN);
        if(t!=0)
        {
            printf("\n");
        }

    }

    return 0;
}
