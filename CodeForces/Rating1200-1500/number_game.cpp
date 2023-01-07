#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void print(bool arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i];
    }
    cout << endl;
}

void solve(){
    int n;
    cin >> n;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    bool arr[n] = {0};
    int a = 1;
    int i = 0, j = n-1;
    while(true){
        if(a!=1){
            if(v[i] == 1 && arr[i] == 0){
                // cout << "Index" << i << endl;
                arr[i] = 1;
                i++;
            }
            else{
                cout << a - 1 << endl;
                return;
            }
        }
        while(!(v[j] <= a && arr[j] == 0) && j >= i){
            j--;
        }
        if(j >= i && v[j] <= a && arr[j] == 0){
            // if(v[j] == 1)
            // cout << "Index" << j  << a << endl;

            arr[j] = 1;
            a++;
            // cout << "J" << j << endl;
            j = n-1;
        }
        else{
            cout << a-1 << endl;
            return;
        }
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