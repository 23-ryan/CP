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

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int>v;

    int a;
    for(int i=0; i<m; i++){
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    int numPar = ceil(n/k);
    
    int i = 0;
    int x = k-1;
    while(numPar > 0 && x < n){
        numPar -= v[i];
        int diff = i;
        while(v[i] == v[diff] && i < x){
            i++;
        }

        for(int j=i; j<x; j++){
            v[j] -= v[diff];
        }

        diff = i - diff;
        x += diff;
    }
    if(numPar == 0){
        LOG("YES");
    }
    else{
        LOG("NO");
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