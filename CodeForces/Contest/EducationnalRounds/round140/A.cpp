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
    vector<int> X;
    vector<int> Y;
    int  x, y;
    for(int i=0; i<3; i++){
        cin >> x >> y;
        X.push_back(x);
        Y.push_back(y);
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    if((X[0] < X[1] && X[1] < X[2]) || (Y[0] < Y[1] && Y[1] < Y[2])){
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