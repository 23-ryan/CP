#include<iostream>
#include<cmath>
#include<string>
#include<vector>
using namespace std;

long long unsigned int getNumRelPrime(long long unsigned int x, long long unsigned int m, long long unsigned int a){
    vector<int> v;
    for(int i=2; i*i<=x; i++){
        if(x%i == 0){
            v.push_back(i);
            while(x%i==0){
                x /= i;
            }
        }
    }
    if(x > 1){
        v.push_back(x);
    }

    long long unsigned int num = 0;
    for(int msk = 1; msk < (1<<v.size()); msk++){
        long long int mul = 1;
        long long int numFact = 0;
        for(int i=0; i<v.size(); i++){
            if(msk & (1<<i)){
                mul*=v[i];
                numFact++;
            }
        }
        long long unsigned int cur = (m/a)/mul;
        if(numFact%2){
            num+=cur;
        }
        else{
            num-=cur;
        }
    }

    return m/a - num;
}


void solve(){
    long long unsigned int n, m;
    cin >> n >> m;
    long long unsigned int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    long long unsigned int grr[n] = {0};
    grr[0] = 1;

    for(int i=1; i<n; i++){
        long long unsigned int numArr = 0;
        long long unsigned int ai1 = arr[i-1];
        long long unsigned int ai2 = arr[i];
        if(ai1%ai2 != 0){
            cout << 0 << endl;
            return;
        }
        else if(ai1 == ai2){
            numArr += (m/ai1);
        }
        else{
            long long unsigned int x = ai1/ai2;
            numArr+=getNumRelPrime(x, m, ai2);
        }
        grr[i] = numArr;
    }
    long long unsigned int num = 1;
    for(int i=1; i<n; i++){
        num = (num*grr[i])%998244353;
    }
    cout << num << endl;

}

int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        solve();
    }
    return 0;
}