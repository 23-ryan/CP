#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<bitset>
#include<climits>

using namespace std;

# define itn int
# define LOG(x) cout << x << endl
// # define P 1000000007

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    ll arr[n];
    ll dp[n][n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j){
                dp[i][j] = arr[i];
            }
            else{
                dp[i][j] = 0;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=i; j>=0; j--){
            for(int k=i; k<n; k++){
                if(j-1 >= 0 && max(dp[j][k] + arr[j-1], abs(arr[k] -  arr[j-1])*(k - j + 2)) > dp[j-1][k]){
                    dp[j-1][k] = max(dp[j][k] + arr[j-1], abs(arr[k] -  arr[j-1])*(k - j + 2));
                }

                if(k+1 < n && max(dp[j][k] + arr[k+1], abs(arr[k+1] -  arr[j])*(k - j + 2)) > dp[j][k+1]){
                    dp[j][k+1] = max(dp[j][k] + arr[k+1], abs(arr[k+1] -  arr[j])*(k - j + 2));
                }
                
            }
        }
    }
    LOG(dp[0][n-1]);
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