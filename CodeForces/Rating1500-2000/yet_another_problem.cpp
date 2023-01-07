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


void handle(int arr[], int n){
    int l, r;
    cin >> l >> r;
    int xo = 0;
    bool allZero = true;
    for(int i=l-1; i<=r-1; i++){
        if(arr[i] != 0){
            allZero = false;
        }
        xo = xo^arr[i];
    }

    if(xo == 0 && allZero){
        LOG(0);
    }
    else if(xo == 0){
        if(((r-l+1) & 1)){
            LOG(1);
        }
        else{
            int num = 0;
            int xoxo = 0;
            bool currAllZero = true;
            for(int i=l-1; i<r; i++){
                if(currAllZero && arr[i]!=0){
                    currAllZero = false;
                }
                xoxo = xoxo^arr[i];
                num++;
                
                if(xoxo == 0 && (num & 1) && currAllZero){
                    LOG(1);
                    return;
                }
                else if(xoxo == 0 && (num & 1)){
                    currAllZero = true;
                    while(i < r){
                        if(arr[i] != 0){
                            currAllZero = false;
                            break;
                        }
                        i++;
                    }
                    if(currAllZero){
                        LOG(1);
                    }
                    else LOG(2);
                    return;
                }

            }
            if(allZero){
                LOG(0);
            }
            else{
                LOG(-1);
            }
        }
    }
    else{
        LOG(-1);
    }
}


void solve(){
    int n, m;
    cin >> n >> m;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=0; i<m; i++){
        handle(arr, n);
    }
        
}

int main()
{
    solve();
    return 0;
}