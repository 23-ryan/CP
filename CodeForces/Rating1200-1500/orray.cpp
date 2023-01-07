#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<cassert>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int arr[n];
    int ma = 0;
    vector<int> v;

    int orMax = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        ma = max(arr[i], ma);
        orMax = orMax | arr[i];
    }

    while(orMax != 0){
        int a = 0;
        int dig = -1;
        for(int i=0; i<n; i++){
            if(arr[i] == -1) continue;

            else if(a < (orMax & arr[i])){
                a = (orMax & arr[i]);
                dig = i;
            }
        }
        assert(dig != -1);
        v.push_back(arr[dig]);
        orMax = (orMax & ~arr[dig]);
        arr[dig] = -1;
    }

    for(int i=0; i<n; i++){
        if(arr[i] != -1)
            v.push_back(arr[i]);
    }
    for(int i=0; i<n; i++){
        cout << v[i] << " ";
    }
    cout << endl;

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