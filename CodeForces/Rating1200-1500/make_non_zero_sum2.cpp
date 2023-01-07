#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<cassert>
using namespace std;
// VERY BAD CODE --> DIFFICULT TO UNDERSTAND
void solve(){
    int n;
    cin >> n;
    int arr[n];
    int numNonZero = 0;
    vector<int> v;
    int numPar = 0;
    for(int i=0; i<n; i++){
        cin>> arr[i];
        if(arr[i] != 0)
            numNonZero++;
    }

    if(numNonZero%2){
        cout << "-1" << endl;
        return;
    }
    else{
        int a = -1, b;
        int c = 0;
        for(int i=0; i<n; i++){
            if(arr[i] != 0){
                if(a == -1){
                    if(c!=0){
                        v.push_back(c);
                        numPar++;
                        c = 0;
                    }
                    a = i;
                    continue;
                }
                else if(a != -1){
                    b = i;
                    int numZeros = b - a - 1;
                    if((!numZeros%2 && arr[a]*arr[b] > 0) || (numZeros%2 && arr[a]*arr[b] < 0)){
                        v.push_back(numZeros + 2);
                        numPar++;
                    }
                    else{
                        v.push_back(1);
                        v.push_back(numZeros + 1);
                        numPar+=2;
                    }
                    a = -1;
                    c = 0;
                    continue;
                }
            }
            if(i == n-1){
                v.push_back(c+1);
                numPar++;
            }
            c++;
        }
    }
    int a = 1;
    cout << numPar << endl;
    assert(numPar == v.size());
    for(int i=0; i<v.size(); i++){
        cout << a << " " << a+v[i]-1 << endl;
        a = a+v[i];
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