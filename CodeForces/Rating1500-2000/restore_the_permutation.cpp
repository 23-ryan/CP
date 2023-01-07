#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<cassert>
#include<set>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int arr[n/2] = {0};
    set<int> unu;
    bool isThere[n] = {0};
    bool y = true;
    for(int i=0; i<n/2; i++){
        cin >> arr[i];
        if(isThere[arr[i]-1] == 1){
            y = false;
        }
        isThere[arr[i]-1] = 1;
    }
    if(!y){
        cout << "-1" << endl;
        return;
    }
    int j=0;
    for(int i=0; i<n; i++){
        if(isThere[i] == 0){
            unu.insert(i+1);
            j++;
        }
    }
// insert and delete in operation takes inly O(logN) time so that's why it works and using binary search and that iterating back to ck=heck the first unseen doesn't
    int pair[n/2] = {0};
    for(int i=n/2-1; i>=0; i--){
        set<int>::iterator it = unu.upper_bound(arr[i]);
        if(it == unu.begin()){
            cout << "-1" << endl;
            return;
        }

        int first_less = *prev(it);
        unu.erase(first_less);
        pair[i] = first_less;
        // cout << first_less << "  oii" << endl;        
    }
    for(int i=0; i<n/2; i++){
        cout << pair[i] << " " << arr[i] << " ";
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