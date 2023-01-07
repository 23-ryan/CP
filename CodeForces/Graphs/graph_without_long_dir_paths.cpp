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

void doDFS(int st, vector<int> adj[], bool vis[], bool inOut[]){
    vis[st-1] = 1;
    int l = adj[st-1].size();
    for(int i=0; i<l; i++){
        if(vis[adj[st-1][i]-1] == 1 && !(inOut[st-1]^inOut[adj[st-1][i]-1])){
            LOG("NO");
            exit(0);
        }
        else if(vis[adj[st-1][i]-1] == 0){
            inOut[adj[st-1][i]-1] = !inOut[st-1];
            doDFS(adj[st-1][i], adj, vis, inOut);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    pair<int,int> edge[m];
    vector<int> adj[n];
    int x, y;

    for(int i=0; i<m; i++){
        cin >> x >> y;
        edge[i].first = x;
        edge[i].second = y;
        adj[x-1].push_back(y);
        adj[y-1].push_back(x);

    }
    bool vis[n] = {0};
    bool inOut[n] = {0};

    inOut[0] = 1;
    doDFS(1, adj, vis, inOut);

    string s = "";
    for(int i=0; i<m; i++){
        if(inOut[edge[i].first-1] == 1 && inOut[edge[i].second-1] == 0){
            s+='1';
        }
        else{
            s+='0';
        }
    }
    LOG("YES");
    LOG(s);
    return 0;
}