#include<iostream>
#include<cmath>
#include<vector>
#include<string>

// 3^11  --> 3.3^10 --> 3.(9)^5 --> 3.9.(81^2) --> 3.9.(729) --> ans
// 11 -> 10(1)(1) --> these 3 and 9 are just taking care of those (1) bits at the end.
// 3^12 --> 9^6 --> 81^3 --> 81.(81)^2
// 12 -> 1(1)00

// to calculate the mod in case of division then you just have to use fermat's little theorem
using namespace std;

int power(int a, int b){
    int result = 1;
    while(b>0){
        if(b%2 == 1){
            result *= a;
        }
        a *= a;
        b/=2;
    }
    return result;
}


// WORST CASE O(sqrt(N))
// Could be done in O(log(N)) using sieve method
vector<int> getPrimeFactors(int n){
    vector<int> v;
    for(int i=2; i*i<=n; i++){
        if(n%i == 0){
            v.push_back(i);
            while(n%i == 0)
                n /= i;
        }
    }
    if(n > 1){
        v.push_back(n);
    }
    return v;
}


