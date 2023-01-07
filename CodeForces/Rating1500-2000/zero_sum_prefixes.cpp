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

# define itn int
#define ll long long

using namespace std;
void solve(){
    int n;
    cin >> n;
    ll int arr[n];
    ll int pref[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    pref[0] = arr[0];
    for(int i=1; i<n; i++){
        pref[i] = pref[i-1] + arr[i];
    }

    ll int st = 0;
    ll int score = 0;
    ll int score_no_zeros = 0;
    while(st < n){
        if(arr[st] == 0){
            map<ll int, ll int>A;
            while(st < n){
                A[pref[st]]++;
                st++;

                // TO PREVENT FROM INDEX OUT OF BOUNDS ERROR //
                if(st < n){
                    if(arr[st]==0){
                        break;
                    }
                }
            }
            ll int maxfreq = 0;
            ll int l = A.size();
            for(auto it = A.begin(); it!= A.end(); it++){
                if(it->second > maxfreq){
                    maxfreq = it->second;
                }
            }
            score += maxfreq;
        }
        else{
            if(pref[st] == 0){
                score_no_zeros++;
            }
            st++;
        }
    }
    cout << score+score_no_zeros << endl;
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