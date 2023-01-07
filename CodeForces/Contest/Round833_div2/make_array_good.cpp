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


bool comp(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    int x;
    for(int i=0; i<n; i++){
        cin >> x;
        v.push_back(make_pair(x, i));
    }
    sort(v.begin(), v.end(), comp);

    vector<pair<int, int>> numOp;
    for(int i=0; i<n-1; i++){
        if(v[i+1].first%v[i].first == 0) continue;
        else{
            int mul = 2;
            while(mul*v[i].first < v[i+1].first){
                mul++;
            }
            int target = mul*v[i].first;
            int a = target/v[i+1].first - 1;
            int b = target - (target/v[i+1].first)*v[i+1].first;
            while(a != 0){
                numOp.push_back(make_pair(v[i+1].first, v[i+1].second));
                a--;
            }
            v[i+1].first = target;
            numOp.push_back(make_pair(b, v[i+1].second));
        }
    }
    LOG(numOp.size());
    int sz = numOp.size();
    for(int i=0; i<sz; i++){
        LOG(numOp[i].second + 1 << " " << numOp[i].first);
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