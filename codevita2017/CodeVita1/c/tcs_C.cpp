#include<iostream>
#define INC 0
#define DECR 1

using namespace std;

int main(){
    int t;
    cin>>t;
    int n=4*(t-2)+6;
    char str[n];
    cin>>str;

    int i=0;
    int flag=INC;
    do{

        if(str[i]=='X')
            return 0;
        if(flag==0){
            if(i==n-2 || i==n-3){
                flag=DECR;
            }
            else{
                cout<<str[i];
                if(i==0 || i==n-5){
                    i+=3;
                    continue;
                }
                i+=4;
            }
        }
        if(flag == DECR){
            if(i==0 || i==1 || i==2){
                flag=INC;
            }
            else{
                cout<<str[i];
                if(i==n-2){
                    i-=2;
                    continue;
                }
                if(i==n-3 || i==4){
                    i-=3;
                    continue;
                }
                i-=4;
            }
        }
    }while(i!=2);
    cout<<str[i];
    return 0;
}
