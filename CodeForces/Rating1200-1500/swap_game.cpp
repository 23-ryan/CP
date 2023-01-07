#include<iostream>
#include<cmath>
#include<string>
#include<climits>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int arr[n];
    int minElem = INT_MAX;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        minElem = min(minElem, arr[i]);
    }
    if(minElem == arr[0]){
        cout << "Bob" << endl;
    }
    else{
        cout << "Alice" << endl;
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