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

void getGO1(int st, vector<int> adj[], vector<int>& go, int x, bool vis[], vector<int>& leafs){
    vis[st-1] = 1;
    if(adj[st-1].size() == 1){
        leafs.push_back(st);
    }
    for(auto i : adj[st-1]){
        if(vis[i-1] == 0){
            go[i-1] = x;
            getGO1(i, adj, go, x, vis, leafs);
        }
    }
}

void getGO(int st, vector<int> adj[], vector<int>& go, int x, bool vis[]){
    vis[st-1] = 1;
    for(auto i : adj[st-1]){
        if(vis[i-1] == 0){
            go[i-1] = x;
            getGO(i, adj, go, x, vis);
        }
    }
}

void setDist(int st, vector<int> adj[], vector<pair<int, int>> arr[], bool vis[], int root, int lev){
    vis[st-1] = 1;
    arr[lev].push_back(make_pair(root, st));
    for(auto i : adj[st-1]){
        if(vis[i-1] == 0){
            setDist(i, adj, arr, vis, root, lev+1);
        }
    }
}

void doDFS(int st, vector<int> adj[], vector<pair<int, int>> arr[], bool vis[], int n){
    vis[st-1] = 1;
    for(auto i : adj[st-1]){
        if(vis[i-1] == 0){
            bool visvis[n] = {0};
            visvis[st-1] = 1;
            setDist(i, adj, arr, visvis, st, 1);
            doDFS(i, adj, arr, vis, n);
        }
    }
}


void solve(){
    int n;
    string s;
    cin >> n >> s;
    vector<int> adj[n];
    int x, y;
    for(int i=0; i<n-1; i++){
        cin >> x >> y;
        adj[x-1].push_back(y);
        adj[y-1].push_back(x);
    }

    vector<int> go[n];
    for(int i=0; i<n; i++){
        go[i] = vector<int>(n, 0);
    }
    vector<pair<int, int>> arr[n];

    for(int i=0; i<n; i++){
        bool vis[n] = {0};
        vis[i] = 1;
        for(auto j : adj[i]){
            go[i][j-1] = j;
            getGO(j, adj, go[i], j, vis);
        }
    }

    for(int i=0; i<n; i++){
        bool vis[n] = {0};
        doDFS(i+1, adj, arr, vis, n);
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<arr[i].size(); j++){
            // cout << go[i][j] << " ";
            cout << arr[i][j].first << " " << arr[i][j].second << "--";
        }
        LOG("");
    }

    int dp[n][n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j){
                dp[i][j] = 1;
            }
            else
                dp[i][j] = 0;
        }
    }

    int tell;
    for(auto i: arr[1]){
        tell = (s[i.first-1] == s[i.second - 1]);
        dp[i.first-1][i.second-1] = 1 + tell;
        // dp[i.second-1][i.first-1] = dp[i.first-1][i.second-1];
    }


    for(int i=2; i<=2; i++){
        for(auto j : arr[i]){

            tell = (s[j.first-1] == s[j.second - 1]);
            dp[j.first-1][j.second-1] = max(max(dp[go[j.first-1][j.second-1]-1][j.second-1], dp[j.first-1][go[j.second-1][j.first-1]-1]), 2*(tell) + dp[go[j.first-1][j.second-1]-1][go[j.second-1][j.first-1]-1]);
            // dp[j.second-1][j.first-1] = dp[j.first-1][j.second-1];
            // if(go[j.first-1][j.second-1] == go[j.second-1][j.first-1]){
            //     // cout << j.first << " " << j.second << " " << dp[j.first-1][j.second-1] << "-" << go[j.second-1][j.first-1] << " " << go[j.first-1][j.second-1] << endl;
            //     // cout << dp[go[j.first-1][j.second-1]-1][j.second-1] << " " << dp[j.first-1][go[j.second-1][j.first-1]-1] << " " << dp[go[j.first-1][j.second-1]-1][go[j.second-1][j.first-1]-1] << endl;
            //     LOG(dp[go[j.first-1][j.second-1]-1][go[j.second-1][j.first-1]-1] << " " << j.first << j.second);
            //     LOG("=====");
            // }
        }
    }
    int maxPal = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            maxPal = max(maxPal, dp[i][j]);
            cout << dp[i][j] << " ";
        }
        LOG("");
    }
    LOG(maxPal);

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