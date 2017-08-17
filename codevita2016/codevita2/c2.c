
#include<stdio.h>

int main()
{

 int sum=0;
 int n;
 int num;
 int tmp;

 int countNeg=0;
 int countPos=0;
 int arr[26];

 int expArr[26];

 scanf("%d",&n);
 int i;
 for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        sum+=arr[i];
    }

 if(sum%n!=0) printf("No");

 else
    {
        tmp=sum/n;

        if(n%2==0)
            {
                expArr[n/2-1]=tmp-1.5;
                for(i=n/2-2;i>=0;i--)
                {
                    expArr[i]=expArr[i+1]-3;
                }

                for(i=n/2;i<n;i++)
                {
                    expArr[i]=expArr[i-1]+3;
                }

            }
        else if(n%2!=0)
            {
                expArr[(int)(n/2)]=tmp;
                for(i=(int)(n/2)-1;i>=0;i--)
                {
                    expArr[i]=expArr[i+1]-3;
                }

                for(i=(int)(n/2)+1;i<n;i++)
                {
                    expArr[i]=expArr[i-1]+3;
                }

            }

            //for(i=0;i<n;i++) printf("%d ",expArr[i]);

        for(i=0;i<n;i++)
        {
            arr[i]=arr[i]-expArr[i];
            if(arr[i]<0) countNeg++;
            else if(arr[i]>0) countPos++;
        }

        if(countNeg>countPos) printf("Yes %d",countNeg);
        else printf("Yes %d",countPos);

    }

 return 0;
}


