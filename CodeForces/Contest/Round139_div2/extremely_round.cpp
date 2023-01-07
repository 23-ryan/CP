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

using namespace std;
void solve(){
    int n;
    cin >> n;
    long long i=1;
    int score = 0;
    // if(i == 1){

    // }
    while(n >= i){
        score += 9;
        i = 10*i;
    }
    score -= 9;
    score += (n/(i/10));
    cout << score << endl;

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