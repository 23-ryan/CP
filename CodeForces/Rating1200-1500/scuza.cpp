#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int getHeight(int st, int en, int x, int arr[]){
    if(x >= arr[en]) return en;
    else if(x < arr[st]) return st;
    else if(arr[(st+en)/2] <= x){
        return getHeight((st+en)/2, en, x, arr);
    }
    else if(arr[(st+en)/2] > x){
        return getHeight(st, (st+en)/2 + 1, x, arr);
    }
}

void solve(){
    int n, q;
    cin >> n >> q;
    int arr[n] = {0};
    int ques[q] = {0};
    int arrMax[n] = {0};
    long long unsigned int heights[n] = {0};
    int ma = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        ma = max(ma, arr[i]);
        arrMax[i] = ma;
        if(i!=0){
            heights[i] = heights[i-1] + arr[i];
        }
        else heights[i] = arr[i];
    }

    for(int i=0; i<q; i++){
        cin >> ques[i];
        if(ques[i] == 0){
            cout << 0 << " ";
        }
        else{
            int a = getHeight(0, n-1, ques[i], arrMax);
            cout << heights[a] << " ";
        }
    }
    cout << endl;
}

int main()
{
    int t;
    cin >>t;
    for(int i=0; i<t; i++){
        solve();
    }
    return 0;
}