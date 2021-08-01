#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
/** 
*  \brief This will return power includeing modulo
*  \param a "first number"
*  \param b "second number"
*  \param mod "modulo of number"
* \return pow(a,b)%mod    
*/
ll Binary_Expotential_using_loop(ll a, ll n, ll m = 1000000007)
{
    a %= m;
    ll res = 1;
    while (n)
    {
        if (n & 1)
            res = (res % m * a % m) % m;
        a = (a % m * a % m) % m;
        n >>= 1;
    }

    return res;
}


/** 
*  \brief This is fast gcd
*  \param a "first number"
*  \param b "second number"
*  \return fast gcd(a,b)    
*/
ll fast_gcd(ll a, ll b)
{
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do
    {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}

/** 
*  \brief This is fast lcm
*  \param a "first number"
*  \param b "second number"
*  \return fast lcm(a,b)    
*/
ll fast_Lcm(ll a,ll b){
    return (a * b) / fast_gcd(a, b);
}



/** 
*  \brief This is ax*by=gcd(a,b)
*  \param a "first number"
*  \param b "second number"
*  \param x "reference to x"
*  \param y "reference to y"
*  \return fast gcd(a,b)    
*/
int Extended_Euclidean_Algorithm(int a, int b, int &x, int &y)
{
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1)
    {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}






int main(){

  //  cout << fast_Lcm(2, 6);

    int x, y;
    cout << Extended_Euclidean_Algorithm(5, 6, x, y);
    cout << x << " " << y; 


}
