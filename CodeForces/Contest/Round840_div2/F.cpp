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


void doDFS(int st, int en, vector<int> adj[], bool vis[], int x, int par[]){
    vis[st-1] = 1;
    int l = adj[st-1].size();
    for(int i=0; i<l; i++){
        if(vis[adj[st-1][i]-1] == 0){
            par[adj[st-1][i] - 1] = st;
            doDFS(adj[st-1][i], en, adj, vis, x, par);
        }
        else if(vis[adj[st-1][i]-1] == 1 && adj[st-1][i] != st){
            int num = 0;
            int a = st;
            while(a != adj[st-1][i]){
                a = par[a-1];
            }
        }
    }
}   


void solve(){
    itn n, m;
    cin >> n >> m;

    vector<int> adj[n];
    int x, y;
    for(int i=0; i<m; i++){
        cin >> x >> y;
        adj[x-1].push_back(y);
        adj[y-1].push_back(x);
    }
    
    int numQ;
    cin >> numQ;
    int st, en;
    int ans = 0;
    for(int i=0; i<numQ; i++){
        cin >> st >> en;
        bool vis[n] = {0};
        int par[n] = {0};
        doDFS(st, en, adj, vis, ans, par);
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