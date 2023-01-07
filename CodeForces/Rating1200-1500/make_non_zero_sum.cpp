#include<iostream>
#include<cmath>
#include<string>
#include<vector>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int arr[n];
    int grr[n/2] = {0};
    int numNeg = 0;
    for(int i=0; i<n; i++){
        cin>> arr[i];
        if(arr[i] < 0){
            numNeg++;
        }
    }
    if(n%2){
        cout << "-1" << endl;
        return;
    }
    else{
        int a = 0, b = 1, i=0;
        while(b <= n-1){
            if(arr[a] == arr[b])
                grr[i] = 2;
            else
                grr[i] = 1;
            i++;
            a+=2; b+=2;
        }
    }
    int numPar = 0;
    for(int i=0; i<n/2; i++){
        if(grr[i] == 1){
            numPar+=2;
        }
        else if(grr[i] == 2){
            numPar++;
        }
    }
    cout << numPar << endl;
    int a = 1, b = 2;
    for(int i=0; i<n/2; i++){
        if(grr[i] == 2){
            cout << a << " " << b << endl;
            a+=2;
            b+=2;
        }
        else if(grr[i] == 1){
            cout << a <<  " " << a << endl;
            cout << b <<  " " << b << endl;
            a+=2;
            b+=2;
        }
    }
}

int main()
{
    int t;
    cin>> t;
    for(int i=0; i<t; i++){
        solve();
    }
    return 0;
}
