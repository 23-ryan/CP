#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

# define itn int


void solve(){
    long long unsigned int n, c, d;
    cin >> n >> c >> d;
    vector<int> v(n);
    for(long long unsigned int i=0; i<n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end(), greater<int>());
    long long unsigned int sum = 0;
    for(int i=0; i<d && i<n; i++){
        sum+=v[i];
    }

    if(v[0]*d < c){
        cout << "Impossible" << endl;
    }
    else if(sum >= c){
        cout << "Infinity" << endl;
    }
    else{
        long long unsigned int k=1;
        long long unsigned int st = 0;
        long long unsigned int en = d;
        while(st <= en){
            // cout << k << endl;
            long long unsigned int sumCoin = 0;
            for(long long unsigned int i=0; i<d; i++){
                if(i%(k+1) < n){
                    sumCoin+=v[i%(k+1)];
                }
            }
            if(sumCoin >= c){
                st = k+1;
                k = (st+en)/2;
            }
            else{
                en = k - 1;
                k = (st+en)/2;
            }
        }
        cout << k << endl;
        // cout << "Infinity-----------" << endl;
    }
}

int main()
{
    itn t;
    cin >> t;
    for(int i=0; i<t; i++){
        solve();
    }

    return 0;
}