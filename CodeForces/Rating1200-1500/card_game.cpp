#include<iostream>
#include<cmath>
#include<string>
using namespace std;


unsigned int arr[60][60] = {0};

long long unsigned int nCr(int n, int r){
    if(r == 0 || n==r){
        return 1;
    }
    else if(arr[n][r] != 0){
        return arr[n][r];
    }
    else{
        arr[n][r] = (nCr(n-1, r) + nCr(n-1, r-1))%998244353;
        return arr[n][r];
    }
}

void solve(){
    unsigned int n;
    cin >> n;
    long long unsigned int P[30] = {0};
    long long unsigned int Q[30] = {0};
    P[0] = 1;
    Q[0] = 0;

    for(unsigned int i=1; i<n/2; i++){
        Q[i] = P[i-1] + nCr(2*(i+1) - 2, i+1);
        P[i] = Q[i-1] + nCr(2*(i+1) - 1, i+1);
    }

    cout << (P[n/2 - 1])%998244353  << " " << (Q[n/2 - 1])%998244353  << " " << 1 << endl;
}

int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        for(int i=0; i<60; i++){
            for(int j=0; j<60; j++){
                arr[i][j] = 0;
            }
        }
        solve();
    }
    return 0;
}