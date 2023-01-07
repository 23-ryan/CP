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
    int k, n;
    cin >> k >> n;
    int arr[k] = {0};
    int diff = 1;
    int num = 1;
    int i = 1;
    arr[0] = 1;

    while(i < k && (n-(arr[i-1] + diff) >= (k-i-1))){
        arr[i] = arr[i-1] + diff;
        diff++;
        i++;
    }
    while(i < k){
        arr[i] = arr[i-1] + 1;
        i++;
    }

    for(int i=0; i<k; i++){
        cout << arr[i] << " ";
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