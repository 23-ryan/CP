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

void doDFS(int st, vector<int> adj[], bool vis[], bool isCat[], int m, int currCat, int& totalPaths){
    vis[st-1] = 1;
    
    if(adj[st-1].size() == 1 && st != 1){
        if(currCat + isCat[st-1] <= m){
            totalPaths+=1;
        }
        return;
    }

    int l = adj[st-1].size();
    for(int i=0; i<l; i++){
        if(vis[adj[st-1][i]-1] == 0){
            if(currCat > m) return;
            else if(isCat[st-1]) doDFS(adj[st-1][i], adj, vis, isCat, m, currCat + isCat[st-1], totalPaths);
            else if(!isCat[st-1]) doDFS(adj[st-1][i], adj, vis, isCat, m, 0, totalPaths);
        }
    }
}


int main()
{
    int n, m;
    cin >> n >> m;
    bool isCat[n];
    for(int i=0; i<n; i++){
        cin >> isCat[i];
    }

    vector<int> adj[n];
    int x, y;
    for(int i=0; i<n-1; i++){
        cin >> x >> y;
        adj[x-1].push_back(y);
        adj[y-1].push_back(x);
    }
    bool vis[n] = {0};
    int l = adj[0].size();
    int totalPaths = 0;
    doDFS(1, adj, vis, isCat, m, 0, totalPaths);
    LOG(totalPaths);
    return 0;
}