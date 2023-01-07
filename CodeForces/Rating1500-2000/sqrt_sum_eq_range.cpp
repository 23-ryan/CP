#include<iostream>
#include<cmath>
#include<string>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int arr[n]={0};
    if(n%2){
        for(int i=0; i<n; i++){s
            arr[i] = (n+1)/2 + i + 2;
        }
        arr[0]-=1;
        arr[n-1]+=1;
        arr[n-2]+=1;
        for(int i=0; i<n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else{
        for(int i=0; i<n/2; i++){
            arr[i] = n/2 + i;
        }
        for(int i=n/2; i<n; i++){
            arr[i] = n/2 + i + 1;
        }
        for(int i=0; i<n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
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