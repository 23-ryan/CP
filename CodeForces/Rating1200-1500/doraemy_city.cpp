#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >>n;
    vector<int>v(n, 0);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    // for(int i=0; i<n; i++){
    //     cout << v[i] << " ";
    // }
    // cout << endl;
    unsigned long long l, mid = v[n/2], r;
    unsigned long long numMid = 0;
    unsigned long long a = n/2;
    while(a < n){
        if(v[a] != mid){
          break;
        }
        a--;
        numMid++;
    }
    l = a + 1;

    a = n/2 + 1;
    while(a < n){
        if(v[a] != mid){
            break;
        }
        numMid++;
        a++;
    }
    r = n - l - numMid;
    if(r == 0 && l == 0){
        cout << numMid/2 << endl;
    }
    else{
        cout << max((l+numMid)*r, l*(numMid + r)) << endl;
    }

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