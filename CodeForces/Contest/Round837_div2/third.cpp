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

# define MAXN 100001
int* spf = new int[MAXN];

void seive(){
    spf[1] = 1;
    for(int i=2; i<MAXN; i++){
        spf[i] = i;
    }

    for(int i=4; i<MAXN; i+=2)
        spf[i] = 2;

    for(int i=3; i*i<MAXN; i++){
        if(spf[i] == i){
            for(int j=i*i; j<MAXN; j+=i){
                if(spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

vector<int> getPrimeFactors(int n){
    vector<int> ans;
    while(n!=1){
        ans.push_back(spf[n]);
        n = (n/spf[n]);
    }

    return ans;
}

void solve(){
    int n;
    cin >> n;
    int arr[n] = {0};
    for(int i=0;i<n; i++){
        cin >> arr[i];
    }

    set<int> s;
    for(int i=0; i<n; i++){
        vector<int> v = getPrimeFactors(arr[i]);
        // for(int i=0; i<v.size(); i++){
        //     cout << v[i] << " ";
        // }
        // LOG("");
        for(int i=0; i<v.size(); i++){
            if(s.empty()){
                s.insert(v[i]);
            }
            else if((i >= 1 && v[i] != v[i-1]) || (i==0)){
                auto pos = s.find(v[i]);

                if(pos != s.end()){
                    cout << "YES" << endl;
                    return;
                }
                s.insert(v[i]);
            }
        }
    }
    cout << "NO" << endl;

}

int main()
{
    seive();
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        solve();
    }
    return 0;
}