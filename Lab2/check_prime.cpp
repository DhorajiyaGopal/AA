#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int power(ull a,ull n,ull p)
{
    int val = 2;
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
int gcd(int a,int b)
{
    int r;
    while (b!=0)
    {
        r = a % b;
        a = b ;
        b = r;
    }
    return a;
    
}
bool is_prime_randomized(ull n,int k)
{
    if(n <= 1 || n == 4)
    {
        return false;
    }
    if(n <= 3)
    {
        return true;
    }
    while(k > 0)
    {
        srand(time(0));
        ull a = 2 + (rand() % (n - 4));
        if(gcd(n,a) != 1)
        {
            return false;
        }
        if(power(a,n-1,n) != 1)
        {
            return false;
        }
        k--;
    }
    return true;
}
int main()
{
    srand(time(0));
    cout<<(bool)is_prime_randomized(1223,400);
    
}