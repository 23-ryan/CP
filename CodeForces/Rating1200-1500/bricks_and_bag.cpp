#include<iostream>
#include<cmath>
#include<string>
#include<climits>
using namespace std;

void solve(){
    int n;
    cin >> n;
    long long unsigned int maxNum = 0, minNum = UINT64_MAX;
    long long unsigned int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
        maxNum = max(maxNum, arr[i]);
        minNum = min(minNum, arr[i]);
    }
    if(maxNum == minNum){
        cout << 0 << endl;
        return;
    }
    long long unsigned int minNum2 = UINT64_MAX, maxNum2 = 0;
    for(int i=0; i<n; i++){
        if(arr[i] != minNum){
            minNum2 = min(arr[i], minNum2);
        }
        if(arr[i] != maxNum){
            maxNum2 = max(arr[i], maxNum2);
        }
    }

    cout << max((maxNum - maxNum2), (minNum2 - minNum)) + (maxNum - minNum) << endl;

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