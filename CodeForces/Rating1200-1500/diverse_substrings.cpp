#include<iostream>
#include<cmath>
#include<string>
using namespace std;

void solve(){
    unsigned long long int n;
    cin >> n;
    string s;
    cin >> s;

    // if(n > )
    int arr[10] = {0};
    unsigned long long int numExclStr = 0;

    for(int i=0; i<n; i++){
        int distChar = 0;
        int maxRep = 0;

        for(int j=0; j<10; j++)
            arr[j] = 0;

        for(int j=i; j<n; j++){
            if(j-i == 100){
                // cout << "----===" << numExclStr << endl;
                numExclStr += (n - j);
                break;
            }
            if(arr[s[j] - '0'] == 0){
                distChar++;
            }

            arr[s[j] - '0']++;
            maxRep = max(maxRep, arr[s[j] - '0']);
            if(maxRep > distChar) numExclStr++;
        }

    }
    cout << (n*(n+1)/2) - numExclStr << endl;
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