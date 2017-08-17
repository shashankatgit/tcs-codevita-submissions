#include<math.h>
#include <stdlib.h>
#include<ctype.h>
int main(){
    int t, i;
    char str[20];
    long double p, r;
    scanf("%llf",&p);
    scanf("%llf",&r);
    scanf("%s",&str);
    for(i=0;str[i]!='\0';i++){
        if(!isdigit(str[i])){
            printf("Invalid Input\n");
            return 0;
    }
    }

    t=atoi(str);
    if(t<=0 || p<=0 || r<0){
            printf("Invalid Input\n");
            return 0;
    }

    long double amount=0;
    for(i=0;i<t;i++){
        amount += p + ((amount+p)*r)/1200.0;
    }
    i= round(amount);
    printf("Final_Amount %Lf\n",(double)i);
    return 0;
}
