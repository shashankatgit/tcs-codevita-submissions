#include<stdio.h>
#include<math.h>

int main()
{
 double x,y,va,vb;

 double t;
 double dist;

 scanf("%lf %lf %lf %lf", &x, &y, &va,&vb);

 if(x<=0 || y<=0 || va<=0 || vb<=0) printf("Invalid Input");

 /*
 else
 {
    t = (va*x + vb*y)/(va*va + vb*vb);
    dist = sqrt( (x-va*t)*(x-va*t)+(-y+vb*t)*(-y+vb*t));
    printf("%lf",dist);
 }
 */

 else
 {
    dist = ((vb/va)*x - y)/sqrt((vb/va)*(vb/va)+1.0);
    if(dist<0) dist*=-1;

    if(dist)
     printf("%lf",dist);

    else
     printf("0.0");
 }
 return 0;
}
