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
    return (a.first > b.first);
}

void solve(){
    int n, m;
    cin >> n >> m;
    bool arr[n][m];
    vector<pair<int, int>> v;
    int totalOne = 0;
    for(int i=0; i<n; i++){
        int num = 0;
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                num++;
            }
        }
        totalOne += num;
        v.push_back(make_pair(num, i));
    }

    if(totalOne % n != 0){
        LOG(-1);
        return;
    }

    sort(v.begin(), v.end(), comp);
    
    // LOG(v[0].second);
    int fin = totalOne/n;
    int st = 0, en = n-1;

    string s;
    vector<string> op;
    while(st < en){
        int cnt = min((fin - v[en].first), (v[st].first  - fin));
        for(int i=0; i<m && cnt>0; i++){

            if(v[st].first > fin && v[en].first < fin && ((arr[v[st].second][i]) && !arr[v[en].second][i])){
                // LOG(arr[st][i] << " " << arr[en][i] << i);
                // LOG(v[st].second << v[en].second << i);
                bool temp = arr[v[st].second][i];
                arr[v[st].second][i] = arr[v[en].second][i];
                arr[v[en].second][i] = temp;
                v[st].first--;
                v[en].first++;
                s = to_string(v[en].second + 1) + " " + to_string(v[st].second + 1) + " " + to_string(i+1);
                op.push_back(s);
                cnt--;
            }
        }

        if(v[st].first == fin){
            st++;
        }
        if(v[en].first == fin){
            en--;
        }
    }

    int l = op.size();
    LOG(l);
    for(int i=0; i<l; i++){
        LOG(op[i]);
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