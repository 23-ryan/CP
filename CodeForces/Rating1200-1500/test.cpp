#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int getHeight(int st, int en, int x, int arrMax[]){
    if(en - st == 1){
        if(arrMax[en] <= x) return en;
        else return st;
    }
    else if(arrMax[(st+en)/2] > x){
        en = (st + en)/2;
        return getHeight(st, en, x, arrMax);
    }
    else if(arrMax[(st+en)/2] <= x){
        st = (st+en)/2;
        return getHeight(st, en, x, arrMax);
    }
}

int main()
{   
    int n;
    cin >> n;
    int arrMax[n];
    for(int i=0; i<n; i++){
        cin >> arrMax[i];
    }
    int t;
    cin >> t;
    cout << getHeight(0, n-1, t, arrMax) << endl;
}