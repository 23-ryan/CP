#include<iostream>
#include<cmath>
#include<string>
#include<climits>
using namespace std;




int main()
{
    int n;
    cin >> n;
    int arr[n][n];
    long long unsigned int sum = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            sum+=arr[i][j];
        }
    }

    int mn = INT_MAX;
    for(int i=0; i<n; i++){
        mn = min(mn, arr[i][n-i-1]);
    }

    cout << sum - mn << endl;

    return 0;
}