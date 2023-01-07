#include<iostream>
#include<cmath>
#include<string>
using namespace std;

void solve(){
    int n, x;
    cin >> n >> x;
    int arr[x] = {0};
    int a;
    for(int i=0; i<n; i++){
        cin >> a;
        arr[a-1]++;
    }

    // for(int i=0; i<x; i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    for(int i=0; i<x-1; i++){
        if(arr[i] >= i+2){
            arr[i+1] += (arr[i]/(i+2));
            arr[i] = (arr[i]%(i+2));
        }
    }
    long long unsigned int rem = 0;

    for(int i=0; i<x-1; i++){
        if(arr[i] != 0){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;


}

int main()
{
    solve();
    return 0;
}