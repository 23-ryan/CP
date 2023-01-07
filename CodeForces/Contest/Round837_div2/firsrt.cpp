#include<iostream>
#include<cmath>
#include<string>
#include<climits>
using namespace std;


void solve(){
    int n;
    cin >> n;
    int arr[n];
    int maxNum = 0;
    int minNum = INT_MAX;
    long long unsigned int a=0, b = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        minNum = min(minNum, arr[i]);
        maxNum = max(maxNum, arr[i]);
    }
    for(int i=0; i<n; i++){
        if(arr[i] == maxNum){
            a++;
        }
        if(arr[i] == minNum){
            b++;
        }
    }

    long long unsigned int ans = 1;
    if(maxNum == minNum){
        ans = a*(a-1);
    }
    else{
        ans = a*b*2;
    }
    cout << ans << endl;
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