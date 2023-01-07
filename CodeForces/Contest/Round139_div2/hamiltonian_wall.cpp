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

// JUST TRY TO GO "VERTICAL FIRST,THEN IN THE FORWARD DIRECTION" so that you won't leave any block remaining because if you first move forward then you might leave some black box unvisited.


void solve(){
    itn n;
    cin >> n;
    bool arr[2][n];
    char x;
    int numBlack = 0;
    for(int i=0; i<2; i++){
        for(int j=0; j<n; j++){
            cin >> x;
            if(x == 'W'){
                arr[i][j] = 1;
            }
            else{
                arr[i][j] = 0;
                numBlack++;
            }
        }
    }

    int c=0;
    bool win = false;
    bool loose = false;
    while(c < n && !win && !loose){
        if(arr[0][c] == 0 && !win && !loose){
            int col = c;
            int row = 0;
            bool visited[2][n];
            for(int i=0; i<2; i++){
                for(int j=0; j<n; j++){
                    visited[i][j] = 0;
                }
            }
            int num = 1;
            while(col < n){
                visited[row][col] = 1;
                if(arr[(row+1)%2][col] == 0 && visited[(row+1)%2][col] == 0){
                    row = (row+1)%2;
                    num++;
                }
                else if((col+1 < n) && arr[row][col+1] == 0 && visited[row][col+1] == 0){
                    col = col + 1;
                    num++;
                }
                else if(num == numBlack){
                    win = true;
                    break;
                }
                else{
                    break;
                    loose = true;
                }
            }
        }
        if(arr[1][c] == 0 && !win){
            int col = c;
            int row = 1;
            bool visited[2][n];
            for(int i=0; i<2; i++){
                for(int j=0; j<n; j++){
                    visited[i][j] = 0;
                }
            }
            int num = 1;
            while(col < n){
                visited[row][col] = 1;
                if(arr[(row+1)%2][col] == 0 && visited[(row+1)%2][col] == 0){
                    row = (row+1)%2;
                    num++;
                }
                else if((col+1 < n) && arr[row][col+1] == 0 && visited[row][col+1] == 0){
                    col = col + 1;
                    num++;
                }
                else if(num == numBlack){
                    win = true;
                    break;
                }
                else{
                    loose = true;
                    break;
                }
            }
        }
        c++;
    }

    if(win){
        LOG("YES");
    }
    else if(loose){
        LOG("NO");
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