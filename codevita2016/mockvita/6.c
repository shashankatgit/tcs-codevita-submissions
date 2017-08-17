#include<stdio.h>
#include<limits.h>

#define NUM 4
int sizes[]={1,5,7,10};


int findMinB(int amt)
{
    int i,j;
    int temp;
    if(amt==0) return 0;

    int res = INT_MAX;

    for(i=0;i<NUM ;i++) {

        if(sizes[i]<=amt) {

            temp = findMinB(amt-sizes[i]);
            //printf("%d, ",temp);
            if(temp!=INT_MAX && (temp+1)<res)
                res = temp+1;

        }
    }
    return res;
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

        printf("%d\n",minN);

    }

    return 0;
}
