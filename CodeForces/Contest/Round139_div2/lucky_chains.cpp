#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<unordered_map>
#include<vector>
#include<bitset>
#include<climits>
#include<unordered_set>

using namespace std;


# define itn int
# define MAXN 1000001
# define LOG(x) cout << x << endl

int spf[MAXN];

void sieve()
{   
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
 
        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;
 
    // separately marking spf for every even
    // number as 2
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j=i*i; j<MAXN; j+=i)
 
                // marking spf[j] if it is not
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

unordered_set<int> getFactorization(int x)
{
    unordered_set<int> ret;
    while (x != 1)
    {   
        ret.insert(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

void solve(){
    int x, y;
    cin >> x >> y;

    int i=0;
    if(abs(x - y) == 1){
        cout << -1 << endl;
    }
    else{
        unordered_set<int> primeFac = getFactorization(int(abs(y-x)));
        int minNum = INT_MAX;
        for(auto i : primeFac){
            if(x%i == 0){
                cout << 0 << endl;
                return;
            }
            minNum = min(minNum, ((x/i + 1)*i - x));
        }
        cout << minNum << endl;
    }
}

int main()
{
    sieve();
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        solve();
    }
    return 0;
}