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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int zero[n] = {0};
    int one[n] = {0};
    int nO = 0, nZ = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '0'){
            nZ++;
        }
        else{
            nO++;
        }
        zero[i] = nZ;
        one[i] = nO;
    }

    int numPl = 0;
    for(int )
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