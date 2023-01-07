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
    bool a = true;
    for(int i=0; i<n; i++){
        if(a){
            a = false;
        }
        else if(!a){
            if(s[i] != s[i+1]){
                LOG("NO");
                return;
            }
            i++;
            a = true;
        }
    }
    LOG("YES");
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