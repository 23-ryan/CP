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
    int an = -1;
    int orr = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        if(an == -1){
            an = arr[i];
        }
        else{
            an &= arr[i];
        }
        orr = (orr | arr[i]);
    }
    LOG(orr - an);

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