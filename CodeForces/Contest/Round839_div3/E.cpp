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
    itn n;
    cin >> n;
    int arr[n];
    int F=0, S = 0, B = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        if(arr[i] != i+1){
            F++;
        }
        if(arr[i] != n-i){
            S++;
        }
        if(arr[i] != i+1 && arr[i] != n-i){
            B++;
        }
    }
    if(F <= S-B){
        LOG("First");
    }
    else if(S < F-B){
        LOG("Second");
    }
    else{
        LOG("Tie");
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