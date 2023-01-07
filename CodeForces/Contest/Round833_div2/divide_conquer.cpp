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

void solve(){
    int n;
    cin >> n;
    int arr[n];
    int sum = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    if((sum & 1) == 0){
        LOG(0);
        return;
    }
    else{
        int rem[n];
        for(int i=0; i<n; i++){
            rem[i] = arr[i]%4;
            if(rem[i]%4 == 1 || rem[i]%4 == 2){
                LOG(1);
                return;
            }
        }
        for(int i=0; i<n; i++){
            int re = arr[i]%2;
            int numOp = 0;
            while(arr[i]%2 == re && arr[i] != 0){
                arr[i] = arr[i]/2;
                numOp++;
            }
            if(arr[i]%2 == re){
                rem[i] = -1;
            }
            else rem[i] = numOp;
        }
        int minOp = INT_MAX;
        for(int i=0; i<n; i++){
            if(rem[i]!=-1)
                minOp = min(minOp, rem[i]);
        }
        LOG(minOp);
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