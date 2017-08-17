#include <iostream>     // std::cout
#include <algorithm>    // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <vector>       // std::vector
#include <cstdio>

using namespace std;

int main()
{
 unsigned lon t;

 scanf("%lu",&t);

 while(t--)
 {
    unsigned long n;
    unsigned long long time=0;
    scanf("%lu",&n);
    unsigned long long arr[n];
    for(unsigned long i=0;i<n;i++)
    {
        scanf("%llu",&arr[i]);
    }

    vector<unsigned long long> v(arr,arr+n);

    make_heap(v.begin(),v.end(),greater<unsigned long long>());
    //sort_heap(v.begin(),v.end(),greater<int>());
    time = 0;
    unsigned long long sum = 0;
    for(unsigned long i=0;i<n-1;)
    {
        unsigned long long a,b;
        a = v.front();

        pop_heap(v.begin(),v.end(),greater<unsigned long long>());
        v.pop_back();
        b = v.front();

        pop_heap(v.begin(),v.end(),greater<unsigned long long>());
        v.pop_back();

        //cout<<a<<" "<<b<<endl;
        sum = a+b;
        time+=sum;
        v.push_back(sum);
        push_heap(v.begin(),v.end(),greater<unsigned long long>());
        i+=1;

        //cout<<endl;
    }

    cout<<time<<endl;
 }


 return 0;
}
