#include<iostream>
#include<cmath>
#include<string>
#include<set>
#include<vector>
#include<bitset>

using namespace std;

#define MOD 998244353
 
// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step

vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        // cout << spf[x] << endl;
        x = x / spf[x];
    }
    return ret;
}

// long long unsigned int power(int a, int b){
//     long long unsigned int result = 1;
//     while(b>0){
//         if(b%2 == 1){
//             result = (result * (a)%MOD)%MOD;
//         }
//         a = (a*a)%MOD;
//         b/=2;
//     }
//     return result;
// }

int main()
{
    sieve();
    vector<int> v = getFactorization(20);
    for(int i=0; i<v.size(); i++){
        cout << v[i] << endl;
    }
    return 0;
}