// TLE --> Dont know why??
// According to me, this code works in O(N)

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

#define N 5000001

void solve(){
    char* arr = new char[N];
    int k;
    cin >> arr;
    cin >> k;
    int len = 0;
    for(int i=0; arr[i] != '\0'; i++){
        len++;
    }

    int a = 0;
    int currInd = 0;
    while(k > 0){
        int i=0;
        int index = -1;
        int mn = 100;
        while(i < k+1){
            if(arr[a+i] < mn){
                if(arr[a+i] == '0' && a == 0) break;
                mn = arr[a+i];
                index = a + i;
            }
            i++;
        }
    
        k -= (index - a);
        a = index+1;
        arr[currInd] = arr[index];
        currInd++;

        if(len - a == k){
            a = len;
            break;
        }
    }
    while(a < len){
        arr[currInd] = arr[a];
        currInd++;
        a++;
    }
    arr[currInd] = '\0';

    LOG(arr);
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