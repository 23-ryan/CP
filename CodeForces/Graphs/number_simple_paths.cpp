// NOT CLEAR -->|
// n(n-1) - sum(c_v(c_v - 1)/2) --> basically subtracting the number of combinations which hangs out of the cycle because they won't form multiple paths among them.
// The c_v is taken only for those vertices which has some adjacent node not contained in the  cycle.
// Something is wrong here --> ?? DON'T KNOW WHAT?

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


int numSubTree(int st, vector<int> adj[], bool visvis[]){
    visvis[st-1] = 1;
    int l = adj[st-1].size();
    int total = 0;
    for(int i=0; i<l; i++){
        if(visvis[adj[st-1][i]-1] == 0){
            total += numSubTree(adj[st-1][i], adj, visvis);
        }
    }
    return (total+1);
}


void doDFS(int st, vector<int> adj[], bool vis[], int par[], bool cycle[]){
    vis[st-1] = 1;
    int l = adj[st-1].size();
    for(int i=0; i<l; i++){
        if(vis[adj[st-1][i]-1] == 0){
            par[adj[st-1][i] - 1] = st;
            doDFS(adj[st-1][i], adj, vis, par, cycle);
        }
        else if(vis[adj[st-1][i]-1] == 1 && adj[st-1][i] != par[st-1] && cycle[st-1] != 1){
            int a = st;
            while(a != adj[st-1][i] && a != -1){
                // cout << a << " ";
                cycle[a-1] = 1;
                a = par[a-1];
            }
            if(a != -1){
                // LOG(a);
                cycle[a-1] = 1;
            }
        }
    }
}

void solve(){
    int n;
    cin >> n;
    vector<int> adj[n];
    int x, y;
    for(int i=0; i<n; i++){
        cin >> x >> y;
        adj[x-1].push_back(y);
        adj[y-1].push_back(x);
    }

    bool vis[n] = {0};
    int par[n] = {0};
    par[0] = -1;
    bool cycle[n] = {0};

    doDFS(1, adj, vis, par, cycle);
    // for(int i=0; i<n; i++){
    //     if(cycle[i]){
    //         cout << i+1 << " ";
    //     }
    // }
    // LOG("");
    
    int ans = n*(n-1);
    int total = 0;

    for(int i=0; i<n; i++){
        if(cycle[i]){
            int l = adj[i].size();
            // bool a = true;
            for(int j=0; j<l; j++){
                if(cycle[adj[i][j]-1] != 1){
                    // LOG(adj[i][j]);
                    bool visvis[n] = {0};
                    visvis[i] = 1;
                    total = numSubTree(adj[i][j], adj, visvis);
                    ans -= ((total*(total+1))/2);
                    // a = false;
                }
            }
            // if(a){
            //     ans-=1;
            // }
        }
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