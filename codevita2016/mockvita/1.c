#include<stdio.h>

#define CADD 2
#define CREP 1
#define CDEL 3

#define ascii(x) ((int)x-(int)'a'+1)
#define abs(x) x>0? x:(x*-1)

int main(){
 int i,j,tcount;
 int t;

 char str[1000];
 int freq[27];

 int extraChars = 0;
 int neededChars = 0;

 int temp=0;
 int cost = 0;

 scanf("%d", &t);

 while(t--)
 {
     extraChars = 0;
     neededChars = 0;
     temp=0;
     cost = 0;

     scanf("%s",str);

     for(i=0; i<27; i++) {
        freq[i]=0;
     }

     for(i=0;str[i]!='\0';i++)
     {
        freq[ascii(str[i])]++;

        //printf("%d %d\n",freq[ascii(str[i])],ascii(str[i]));


     }

     for(i=1;i<27;i++)
     {
        if(freq[i]!=0)
        {
            if(freq[i]<i){
                neededChars+= (i-freq[i]);
                //printf("%d, ",neededChars);
            }

            else if (freq[i]>i){
                extraChars+= (freq[i]-i);
                //printf("--%d, ",extraChars);
            }
        }

     }

     temp = neededChars - extraChars;

     if(temp == 0){
        cost = neededChars * CREP;
     }

     else if(temp > 0) {
        cost = extraChars*CREP;

        cost+= (abs(temp))*CADD;
     }

     else {

        cost = neededChars*CREP;

        cost+= (abs(temp)) * CDEL;

     }

     //printf("needed:%d\nextra:%d",neededChars,extraChars);
     printf("%d\n",cost);
 }
return 0;
}
