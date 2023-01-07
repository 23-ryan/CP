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

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    pair<ll, ll> dp[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j){
                if(arr[i] == 0){
                    dp[i][i].first = 1;
                    dp[i][i].second = 0;
                }
                else{
                    dp[i][i].first = 0;
                    dp[i][i].second = 1;
                }
            }
            else{
                dp[i][j].first = 0;
                dp[i][j].second = 0;
            }
        }
    }

    for(int l=0; l<n-1; l++){
        int rightMost = arr[l];
        for(int r=l; r<n-1; r++){
            dp[l][r+1].first = dp[l][r].first;
            dp[l][r+1].second = dp[l][r].second;

            if(arr[r+1] == 0){
                dp[l][r+1].first += 1;
            }
            else if(dp[l][r].second == 1 && ((arr[r+1] == 1 && rightMost == 2) || arr[r+1] == 2 && rightMost == 1)){
                dp[l][r+1].second++;
                rightMost = arr[r+1];
            }
            else if(dp[l][r].second == 0){
                dp[l][r+1].second++;
                rightMost = arr[r+1];
            }
            else{
                rightMost = arr[r+1];
            }
        }
    }

    ll ans = 0;
    for(int l=0; l<n; l++){
        for(int r=l; r<n; r++){
            ans += (dp[l][r].first + dp[l][r].second);
        }
    }
    LOG(ans);
    return 0;
}