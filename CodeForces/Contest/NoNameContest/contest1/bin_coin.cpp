#include<iostream>
#include<cmath>
#include<string>
#include<vector>
using namespace std;


int main()
{   
    int n, k;
    cin >> n>>k;
    int arr[k][n];
    float avg[n] = {0};
    for(int i=0; i<k; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
            // avg[arr[i][j]-1] += j;
        }
    }
    return 0;
}