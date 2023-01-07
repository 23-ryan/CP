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
    int a[2][2];
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cin >> a[i][j];
        }
    }
    if(((a[0][0] < a[1][0] && a[0][0] < a[0][1]) && (a[1][1] > a[1][0] && a[1][1] > a[0][1]) || (a[0][0] > a[1][0] && a[0][0] > a[0][1]) && (a[1][1] < a[1][0] && a[1][1] < a[0][1]))
     || ((a[0][0] < a[1][0] && a[1][1] < a[1][0]) && (a[0][0] > a[0][1] && a[1][1] > a[0][1]) || (a[0][0] > a[1][0] && a[1][1] > a[1][0]) && (a[0][0] < a[0][1] && a[1][1] < a[0][1]))){
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