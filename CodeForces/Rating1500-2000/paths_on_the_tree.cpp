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
#define N 200001
typedef long long ll;



vector<pair<int, ll>> arr[N];
vector<ll> adjList[N];
ll score[N];

ll doDFS(ll st, vector<ll> adj[], ll score[], ll k){
    int sz = arr[st-1].size();
    for(int i=0; i<sz; i++){
        if(arr[st-1][i].first == k){
            return arr[st-1][i].second;
        }
    }
    
    if(adj[st-1].size() == 0){
        arr[st-1].push_back(make_pair(k, score[st-1]*k));
        return score[st-1]*k;
    }
    else{
        ll l = adj[st-1].size();
        ll dp1[l], dp2[l], diff[l];
        for(int i=0; i<l; i++){
            dp1[i] = doDFS(adj[st-1][i], adj, score, k/l);
            dp2[i] = doDFS(adj[st-1][i], adj, score, k/l + 1);

            diff[i] = dp2[i] - dp1[i];
        }
        sort(diff, diff + l, greater<int>());
        ll maxScore = 0;

        for(int i=0; i<l; i++){
            maxScore += dp1[i];
        }
        for(int i=0; i<(k%l); i++){
            maxScore += diff[i];
        }
        arr[st-1].push_back(make_pair(k, maxScore + k*score[st-1]));
        return (maxScore + k*score[st-1]);
    }
}


void solve(){

    ll n, k;
    cin >> n >> k;

    for(int i=0; i<n; i++){
        arr[i].clear();
        adjList[i].clear();
    }
    ll par;

    for(int i=1; i<n; i++){
        cin >> par;
        adjList[par-1].push_back(i+1);
    }
    
    for(int i=0; i<n; i++){
        cin >> score[i];
    }

    doDFS(1, adjList, score, k);
    for(int i=0; i<arr[0].size(); i++){
        if(arr[0][i].first == k){
            LOG(arr[0][i].second);
        }
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