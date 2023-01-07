#include<iostream>
#include<cmath>
#include<string>
#include<vector>
using namespace std;

void incr(int* a, int n, int base, bool* grr){
    int carry = 1;
    int digit;
    for(int i=n-1; i>=0; i--){
        digit = (a[i+1] + carry)%base;
        if(carry >= 1){
            if(grr[digit] == 0){
                grr[digit] = 1;
            }
        }
        carry = (a[i+1] + carry)/base;
        a[i+1] = digit;
        // cout << "D" << digit << endl;
        if(carry == 0){
            break;
        }
    }
    if(carry > 0){
        a[0] = carry;
        if(grr[carry] == 0){
            grr[carry] = 1;
        }
    }
}


void solve(){
    int n, b;
    cin >> n >> b;
    int* arr = new int[n+1];
    bool* grr = new bool[b];

    for(int i=0; i<b; i++){
        grr[i] = 0;
    }
    for(int i=0; i<n; i++){
        cin >> arr[i+1];
        if(grr[arr[i+1]] == 0){
            grr[arr[i+1]] = 1;
        }
    }

    int largeUnseen = 0;
    for(int i=0; i<b; i++){
        if(grr[i] == 0){
            largeUnseen  = i;
        }
    }
    
    int lastDig = arr[n];
    int backUnseen = lastDig;
    for(int i=0; i<=lastDig; i++){
        if(grr[lastDig - i] == 0){
            backUnseen = lastDig - i;
            break;
        }
    }

    int numOp = 0;
    if(lastDig < largeUnseen && !(backUnseen < lastDig)){
        numOp += largeUnseen - lastDig;
    }
    else if(backUnseen < lastDig){
        if(lastDig < b-1){
            numOp += b-1 - lastDig;
            arr[n] = b-1;
        }
        incr(arr, n, b, grr);
        numOp+=1;

        backUnseen = 0;
        for(int i=0; i<lastDig; i++){
            if(grr[i] == 0){
                backUnseen = i;
            }
        }
        lastDig = 0;
        numOp += backUnseen - lastDig;
    }
    cout << numOp << endl;
    delete[] grr;
    delete[] arr;
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