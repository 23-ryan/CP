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

# define NUMLONG 10000000001

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    ll arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    ll lower = NUMLONG, higher = 0;
    for(int i=0; i<n-1; i++){
        if(arr[i] < arr[i+1]){
            lower = min(lower, (arr[i+1] + arr[i])/2);
        }
        else if(arr[i] > arr[i+1]){
            higher = max(higher, (arr[i] + arr[i+1] + 1)/2);
        }
    }

    if(lower == NUMLONG && higher == 0){
        LOG(higher);
    }
    else if(lower == NUMLONG){
        LOG(higher);
    }
    else if(higher == 0){
        LOG(lower);
    }
    else if(higher > lower){
        LOG(-1);
    }
    else{
        LOG(higher);
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