#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int power(ull a,ull n,ull p)
{
    int res = 1;
    a = a % p;
    while(n > 0)
    {
        if(n&1)
        {
            res = (a * res) % p; 
        }
        a = ( a * a) % p;
        n = n >> 1;

    }
    return res;
}
int main()
{
    cout<<power(2,10,100002);
    
}