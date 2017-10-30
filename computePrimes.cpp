// C++ program to print print all primes smaller than
// n using segmented sieve
#include<iostream>

#include<math.h>
#include<vector>
#include<cstring>
using namespace std;

void simpleSieve(int low, int limit){
    bool mark[limit];
    memset(mark,true,sizeof(mark));
    int count = 0;
    for(int p=2;p*p<limit;p++)
    {
        if (mark[p] == true)
        {
            for(int i = p*2; i<limit; i+=p)
                mark[i]=false;
        }
    }
    for(int p =2; p < limit; p++)
    {
        if (mark[p] == true)
        {
            cout << p << " ";
            count ++;
    }



}
    cout << endl;
    cout << count << endl;
}

void segmented(int n)
{
    int low = 0;
    int limit = 10;
    int high = low+limit;

    while(low<n)
    {
        simpleSieve(low,high);
        low = high +1;
        high = high + limit;
        cout << low << endl;
        cout << high << endl;
    }
}


int main(){
    int n = 50;
    segmented(n);
}