#include<iostream>
#include<cmath>
#include<string>
using namespace std;

#define MOD 998244353

int main()
{
    long long unsigned int n, m;
    cin >> n >> m;
    // SEIVE METHOD TO STORE THE PRODUCT OF PRIME FACTORS TILL THAT i
    long long unsigned int arr[n] = {0};
    arr[0] = 1;
    bool grr[n] = {0};
    long long unsigned primeTill = 1;
    for(long long unsigned int i=2; i<=n; i++){
        if(grr[i-1] == 0){
            if(primeTill*i <= m){
                primeTill *= i;
            }
            else if(primeTill != m+1){
                primeTill = m+2;
            }
            
            arr[i-1] = primeTill;
            for(long long unsigned int j=i*i; j<=n; j+=i){
                grr[j-1] = 1;
            }
        }
        else{
            arr[i-1] = primeTill;
        }
    }
    for(long long unsigned int i=0; i<n; i++){
        arr[i] = (m/arr[i])%MOD;
    }

    long long unsigned int total = 0;
    for(int i=0; i<n; i++){
        total = (((m)%MOD * 1ll * total) + (m%MOD))%MOD;
    }

    long long unsigned int mul = 1;
    long long unsigned int sum = 0;
    for(long long unsigned int i=0; i<n; i++){
        if(arr[i] == 0) break;
        mul = ((mul* 1ll * (arr[i])%MOD)%MOD);
        sum = (sum + mul)%MOD;
    }

    cout << ((int(total) - int(sum) + MOD)%MOD) << endl;
    return 0;
}