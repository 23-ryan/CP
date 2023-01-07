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


bool comp(pair<vector<pair<int, int>>, int> a, pair<vector<pair<int, int>>, int> b){
    return (a.first.size() > b.first.size());
}

int main()
{
    int n, m, K;
    cin >> n >> m >> K;
    char arr[K+1][n][m];
    pair<vector<pair<int, int>>, int> grr[K+1];

    for(int i=0; i<K+1; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                cin >> arr[i][j][k];
            }
        }
        grr[i].second = i;
        for(int j=1; j<n-1; j++){
            for(int k=1; k<m-1; k++){
                if(arr[i][j][k] != arr[i][j+1][k] && arr[i][j][k] != arr[i][j][k+1] && arr[i][j][k] != arr[i][j][k-1] && arr[i][j][k] != arr[i][j-1][k])
                    grr[i].first.push_back(make_pair(j, k));
            }
        }
    }


    sort(grr, grr + K+1, comp);
    vector<string> move;

    LOG(grr[0].second + 1);
    for(int i=0; i<K; i++){
        int l = grr[i].first.size();
        string s;

        if(grr[i].first.size() == grr[i+1].first.size()){
            s = ("2 " + to_string(grr[i+1].second + 1));
            move.push_back(s);
            continue;
        }

        for(int j=0; j<l; j++){
            // LOG("--------");
            // LOG(i);
            // LOG(grr[i].first[j].first << grr[i].first[j].second);
            // LOG(arr[grr[i+1].second][grr[i].first[j].first][grr[i].first[j].second] << arr[grr[i].second][grr[i].first[j].first][grr[i].first[j].second]);
            if(arr[grr[i+1].second][grr[i].first[j].first][grr[i].first[j].second] != arr[grr[i].second][grr[i].first[j].first][grr[i].first[j].second]){
                s  = ("1 " + to_string(grr[i].first[j].first + 1) + " " + to_string(grr[i].first[j].second + 1));
                move.push_back(s);
            }
        }

        s = ("2 " + to_string(grr[i+1].second + 1));
        move.push_back(s);
    }

    int l = move.size();
    LOG(move.size());
    for(int i=0; i<l; i++){
        LOG(move[i]);
    }

    return 0;
}