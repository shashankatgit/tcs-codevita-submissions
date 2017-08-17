#include<stdio.h>

int main()
{
 int i,j;

 int n;
 int f,b,t,fd,bd,tmp;
 int dist;
 int dir;
 int trips;
 int time, disp;
 scanf("%d",&n);

 while(n--)
 {
    scanf("%d %d %d %d %d",&f, &b, &t, &fd, &bd);
    dist=0;
    dir = 0; //forward
    if(f-b==0) {
        if(f>=fd)
        {
            printf("\n%d F",fd*t);
        }
        else
            printf("\nNo Ditch");
    }


    else if(fd<f) {
            printf("\n%d F",fd*t);
        }

    else
    {
        time=0;
        dist=0;
        if((b - f)>0)
        {
            fd = bd + f;
            time = f*t;

            tmp = b;
            b= f;
            f=tmp;
            dir=1;

            //printf("extra--%d ",time);
        }


        trips = 0;


            //printf("%d, ",dist);

            trips = (fd - f)/(f-b);
            disp = (f-b)*trips;

            if((disp + f) == fd)
            {
                dist += (f+b)*trips + f;
                time += dist*t;
                //printf("\nequals");
            }

            else
            {
                disp = (f-b)*(trips+1);
                dist += (f+b)*(trips+1) + fd - disp;
                time += dist*t;
                //printf("\nnotequals");
            }
            printf("\n%d",time);
            if(dir==0) printf(" F");
            else printf(" B");
    }

 }
 return 0;
}
