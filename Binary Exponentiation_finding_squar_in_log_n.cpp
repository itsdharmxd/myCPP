//   Binary exponentiation(also known as exponentiation by squaring)  " a^n in log(n) "
//   is a trick which allows to calculate an using only   O(logn)
//   multiplications(instead of O(n) multiplications required by the naive approach).

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll Binary_Expotential_count = 0;
ll Binary_Expotential_count_using_recursion = 0;

//Binary Expotential using recursion
ll Binary_Expotential(ll a, ll n)
      {
          Binary_Expotential_count++;

          if (n == 0)
              return 1;
          
          ll res =Binary_Expotential(a, n / 2);
          if (n % 2)
              return res * res * a;
          else
              return res * res;
       

}

ll Binary_Expotential_using_Rescursion (ll a, ll n,ll m=1000000007)
{
    a %= m;
    ll res = 1;
    while (n)
    {
        Binary_Expotential_count_using_recursion++;
        if(n&1)
            res = (res%m * a%m)%m;
        a = (a%m * a%m)%m;
        n >>= 1;      

    }
    
    return res; 

}

 int main()
 {


    
         cout << Binary_Expotential(10, 8) <<" in " <<Binary_Expotential_count<<endl;

         cout << Binary_Expotential_using_Rescursion(10, 200) << " in " << Binary_Expotential_count_using_recursion << endl;
    
}