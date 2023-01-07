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

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int numZ = 0, numO = 0;
    for(int i=0; i<n; i++){
        if(s[i] == '0') numZ++;
        else numO++;
    }
    // LOG(numO << " " << numZ);
    for(int i=numO+1; i<=(1<<n)-numZ; i++){
        int numLess = i-1;
        int currO = 0;
        while(numLess > 0){
            numLess = (numLess-1)/2;
            currO++;
        }
        int numGrea = (1<<n) - i;
        int currZ = 0;
        while(numGrea > 0){
            numGrea = (numGrea - 1)/2;
            currZ++;
        }
        // LOG(currO << " " << currZ);
        if(currO >= numO && currZ >= numZ){
            cout << i << " ";
        }
    }
    LOG("");

    return 0;
}