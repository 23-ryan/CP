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

void solve(){
    ll n, m;
    cin >> n >> m;
    unordered_map<ll, ll> arr;
    ll x, y, z;
    ll mi = n+1;
    for(int i=0; i<m; i++){
        cin >> x >> y;
        
        z = max(x, y);
        x = min(x, y);
        y = z;

        if(arr[x-1] == 0){
            arr[x-1] = (mi, y);
        }
        else{
            arr[x-1] = min(arr[x-1], y);
        }
    }
    for(int i=0; i<n; i++){
        if(arr[i] == 0){
            arr[i] = -1;
        }
    }

    int i=n-1;
    ll ans = 0;
    while(i >= 0){
        if(arr[i] == -1){
            if(mi == n+1){
                ans += (n - i);
            }
            else{
                ans += (mi - (i+1));
            }
        }
        else{
            mi = min(mi, arr[i]);
            ans += (mi - (i+1));
        }
        i--;
    }
    LOG(ans);

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