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
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int x = 0;
    int i=0;
    int numColor = 1;
    int Color = 0;
    int col[n] = {0};
    bool chkCol[3] = {0};
    int isConti = false;

    while(i < n){
        Color = Color%2 + 1;
        chkCol[Color-1] = true;

        while(arr[x] == arr[i] && i < n){
            col[i] = Color;
            i++;
            if(isConti <= 1)
                isConti++;
        }
        if(i == n && col[i-1] == col[0] && arr[i-1] != arr[0] && ){
            Color = 3;
            chkCol[Color-1] = true;
            while(x < i){
                col[x] = Color;
                x++;
            }
        }
        isConti = 0;
        x = i;
    }

    int numCol = 0;
    for(int i=0; i<3; i++){
        if(chkCol[i]){
            numCol++;
        }
    }

    LOG(numCol);
    for(int i=0; i<n; i++){
        cout << col[i] << " ";
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