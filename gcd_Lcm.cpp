//   Binary exponentiation(also known as exponentiation by squaring)  " a^n in log(n) "
//   is a trick which allows to calculate an using only   O(logn)
//   multiplications(instead of O(n) multiplications required by the naive approach).

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// recursion
ll gcd (ll a,ll b){

if(b==0)
    return a;

return gcd(b, a % b);
}

//loop
ll gcd_loop(ll a, ll b)
{

   while (b)
   {
       a = a % b;
       swap(a, b);
   }
   return a;
}


ll lcm(ll a, ll b){

    return (a * b) / gcd_loop(a, b); 

}

int main()
{
  
}