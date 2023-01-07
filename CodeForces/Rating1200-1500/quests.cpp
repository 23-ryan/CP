#include<iostream>
#include<cmath>
#include<string>
using namespace std;

void solve(){
    int n, d;
    long long unsigned c;
    cin >> n >> c >> d;
    long long unsigned arr[n];
    long long unsigned  sum = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    // CHECK FOR INFITY
    if(sum >= c){
        cout << sum << endl;
        cout << "Infinity" << endl;
    }
    // CHECK FOR NO SOLUTION
    else if(sum*d < c){
        cout << "Impossible" << endl;
    }
    // FINDING THE MAXIMUM SOLUTION
    else{
        int sol = 0;
        long long unsigned chk = (d+sol)/(sol + 1)*sum;
        // cout << chk << "Here" << endl;
        while(chk >= c){
            sol++;
            chk = (d+sol)/(sol + 1)*sum;
            // cout << chk << "Here" << endl;
        }
        cout << sol-1 << endl;
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