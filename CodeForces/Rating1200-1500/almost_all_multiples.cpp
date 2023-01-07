#include<iostream>
#include<cmath>
#include<string>
using namespace std;

void solve(){
    int n, x;
    cin>> n >> x;
    long long unsigned int arr[n] = {0};
    for(int i=0; i<n; i++){
        arr[i] = i+1;
    }
    arr[0] = x;
    arr[n-1] = 1;


    if(n==x){
        for(int i=0; i<n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }

    else if(n!=x)
        arr[x-1] = n;


    if(n%x != 0){
        cout << "-1" << endl;
        return;
    }
    else{
            int mul_x = 2;
            while(mul_x*x - 1 < n-1){
                if(n % (mul_x*x)  == 0){
                    arr[mul_x*x - 1] = n;
                    arr[x - 1] = mul_x*x;


                    x = mul_x*x;
                    mul_x = 2;
                    continue;
                }
                mul_x++;
            }
    }

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
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