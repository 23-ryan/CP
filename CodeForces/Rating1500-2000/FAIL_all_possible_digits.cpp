#include<iostream>
#include<cmath>
#include<string>
#include<vector>
using namespace std;


void incr(int a[], int n, int base, int &numThere, bool grr[]){
    int carry = 1;
    int digit;
    for(int i=n-1; i>=0; i--){
        digit = (a[i+1] + carry)%base;
        if(carry >= 1){
            if(grr[digit] == 0){
                grr[digit] = 1;
                numThere++;
            }
        }
        carry = (a[i+1] + carry)/base;
        a[i+1] = digit;
        // cout << "D" << digit << endl;
        if(carry == 0){
            break;
        }
    }
    if(carry>0){
        if(grr[carry] == 0){
            grr[carry] = 1;
            numThere++;
        }
        a[0] = carry;
    }
}

void solve(){
    int n, b;
    cin >> n >> b;
    int arr[n+1];
    arr[0] = 0;
    bool grr[b] = {0};
    int numThere = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i+1];
        if(grr[arr[i+1]] == 0){
            grr[arr[i+1]] = 1;
            numThere++;
        }
        
    }

    int numOp = 0;
    while(numThere < b){
        incr(arr, n, b, numThere, grr);
        for(int i=0; i<n+1; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        numOp++;
    }
    cout << numOp << endl;
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