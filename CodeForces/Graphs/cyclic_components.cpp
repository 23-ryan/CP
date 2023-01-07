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

void doDFS(int st, vector<int> adj[], bool vis[], bool& cycle){
    vis[st-1] = 1;
    if(adj[st-1].size() != 2){
        cycle = false;
    }
    int l = adj[st-1].size();
    for(int i=0; i<l; i++){
        if(vis[adj[st-1][i]-1] == 0){
            doDFS(adj[st-1][i], adj, vis, cycle);
        }
    }
    
}

int main()
{
    itn n, m;
    cin >> n >> m;
    vector<int> adj[n];
    int x, y;
    for(int i=0; i<m; i++){
        cin >> x >> y;
        adj[x-1].push_back(y);
        adj[y-1].push_back(x);
    }

    bool vis[n] = {0};
    int i = 0;
    int num = 0;
    while(i < n){
        if(vis[i] == 0 && i < n){
            bool cycle = true;
            doDFS(i+1, adj, vis, cycle);
            if(cycle) num++;
        }
        i++;
    }

    LOG(num);
    return 0;
}