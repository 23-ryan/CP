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
#define P 998244353

typedef long long ll;


ll power(ll a, ll b){
    ll result = 1;
    while(b>0){
        if(b%2 == 1){
            result = (result*a)%P;
        }
        a = (a*a)%P;
        b/=2;
    }
    return result;
}

bool doDFS(int st, vector<int> adj[], int currVis[], ll& numO, ll & numT){
    itn l = adj[st-1].size();
    bool a = true;
    for(int i=0; i<l; i++){
        if(currVis[adj[st-1][i]-1] == 0){
            if(currVis[st-1] == 1){
                currVis[adj[st-1][i]-1] = 2;
                numT++;
            }
            else{
                currVis[adj[st-1][i]-1] = 1;
                numO++;
            }
            a = (a & doDFS(adj[st-1][i], adj, currVis, numO, numT));
        }
        else if((currVis[adj[st-1][i]-1] ^ currVis[st-1]) == 0){ // 1^2 or 2^1
            return false;
        }
    }
    return a;
}

void solve(){
    ll n, m;
    cin >> n >> m;

    vector<int> adj[n];
    int x, y;

    for(int i=0; i<m; i++){
        cin >> x >> y;
        adj[x-1].push_back(y);
        adj[y-1].push_back(x);
    }

    ll numWays = 0;
    int vis[n] = {0};
    int i=0;

    while(i < n){
        ll numO = 0, numT = 0;
        numO++;
        vis[i] = 1;

        if(doDFS(i+1, adj, vis, numO, numT)){
            if(numWays != 0) numWays = (numWays*(power(2, numT) + power(2, numO))%P)%P;
            else numWays = (power(2, numT) + power(2, numO))%P;
        }
        else{
            LOG(0);
            return;
        }

        while(vis[i] != 0 && i < n){
            i++;
        }
    }
    LOG(numWays);
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