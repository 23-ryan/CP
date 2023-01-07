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
    int n, x, y;
    cin >> n >> x >> y;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr, arr+n);

    int currMax = x;
    int i=0;
    int numMatches  = 0;
    while(currMax >= arr[i] && currMax < y){
        currMax++;
        numMatches++;
        i++;
    }
    int m = numMatches - (n - numMatches);
    
    if(currMax == y){
        LOG(numMatches);
    }
    else if(m < 0){
        LOG(-1);
        // LOG("Hello");
    }
    else{
        while(currMax < y && i < n){
            while(arr[i] > currMax && currMax < y){
                if(currMax + m >= y){
                    numMatches += n;
                    currMax += m;
                    while(currMax > y){
                        currMax--;
                        numMatches--;
                    }
                    LOG(numMatches);
                    return;
                }
                else{
                    currMax += m;
                    numMatches += n;
                }
            }
            currMax++;
            numMatches++;
            i++;
        }
        while(currMax < y){
            numMatches += n;
            currMax += n;
        }
        if(currMax > y){
            numMatches -= (currMax-y);
        }
        LOG(numMatches);
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