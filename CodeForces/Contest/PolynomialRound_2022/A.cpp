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
    bool arr[n];
    if(s[0] == '1'){
        bool sign = true;
        int i=1;
        while(i < n){
            if(s[i] == '1'){
                arr[i] = sign;
                sign = !sign;
            }
            i++;
        }
    }
    else{
        bool sign = false;
        int i=1;
        while(i < n){
            if(s[i] == '1'){
                arr[i] = sign;
                sign = !sign;
            }
            i++;
        }
    }
    for(int i=1; i<n; i++){
        if(arr[i]){
            cout << '-';
        }
        else cout << '+';
    }
    LOG("");
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