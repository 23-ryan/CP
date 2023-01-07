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

bool comp(pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
}



void solve(){
    int n, k;
    cin >> n >> k;
    int x;
    vector<pair<int, int>> v;
    for(int i=0; i<n; i++){
        cin >> x;
        v.push_back(make_pair(x, 0));
    }
    for(int i=0; i<n; i++){
        cin >> v[i].second;
    }

    sort(v.begin(), v.end(), comp);

    int minPow[n];
    minPow[0] = v[0].second;
    for(int i=1; i<n; i++){
        minPow[i] = min(minPow[i-1], v[i].second);
    }

    int i = n-1;
    int xx = k;
    while(i >= 0 && xx > 0){
        while(i >= 0 && v[i].first <= k){
            i--;
        }
        if(i < 0 ){
            LOG("YES");
            return;
        }
        k = k + (xx-minPow[i]);
        xx = xx - minPow[i];
    }
    LOG("NO");
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