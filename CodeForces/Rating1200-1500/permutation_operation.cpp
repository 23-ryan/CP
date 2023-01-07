#include<iostream>
#include<cmath>
#include<string>
#include<cassert>
using namespace std;

void solve(){
    int n;
    cin>> n;
    int arr[n] = {0};
    int arrMax[n] = {0};
    int maxElem = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        maxElem = max(maxElem, arr[i]);
        arrMax[i] = maxElem;
    }
    int ans[n] = {0};

    for(int i=n-1; i>=0; i--){
        if(arrMax[i] > arr[i]){
            if(ans[arrMax[i] - arr[i]] == 0){
                ans[arrMax[i] - arr[i]] = i + 1;
            }
            else{
                int a = arrMax[i] - arr[i];
                
                while(a < n && ans[a] != 0){
                    a++;
                    assert(a!=n);
                }
                // a==n not possible;
                ans[a] = i + 1;
            }
        }
    }
    for(int i=0; i<n; i++){
        if(ans[i] == 0){
            cout << 1 << " ";
        }
        else{
            cout << ans[i]  << " ";
        }
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