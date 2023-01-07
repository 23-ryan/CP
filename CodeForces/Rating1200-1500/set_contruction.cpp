#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void getSets(int k, int n, vector<vector<int>> &sets, bool** arr){
    if(k == n) return;
    else{
        int a = k;
        // ROWS
        for(int i=0; i<=k; i++){
            if(arr[a][i]){
                // for(int j=0; j<sets[a].size(); j++){
                //     cout << sets[a][j] << " ";
                // }
                // cout << endl;

                // for(int j=0; j<sets[i].size(); j++){
                //     cout << sets[i][j] << " ";
                // }
                // cout << endl;

                vector<int> v(sets[i].size() + sets[a].size());
                vector<int>::iterator ls = std::set_union(sets[a].begin(), sets[a].end(), sets[i].begin(), sets[i].end(), v.begin());
                // for(vector<int>::iterator it = v.begin(); it!= ls; ++it){
                //     cout << *it << "as ";
                // }
                sets[i].clear();
                v.resize(ls-v.begin());
                sets[i] = v;
                // cout << endl;
            }
        }

        // COLS
        for(int i=0; i<=k; i++){
            if(arr[i][a]){
                // for(int j=0; j<sets[a].size(); j++){
                //     cout << sets[a][j] << " ";
                // }
                // cout << endl;

                // for(int j=0; j<sets[i].size(); j++){
                //     cout << sets[i][j] << " ";
                // }
                // cout << endl;

                vector<int> v(sets[i].size() + sets[a].size());
                vector<int>::iterator ls = std::set_union(sets[a].begin(), sets[a].end(), sets[i].begin(), sets[i].end(), v.begin());
                // for(vector<int>::iterator it = v.begin(); it!= ls; ++it){
                //     cout << *it << "as ";
                // }
                // cout << endl;
                v.resize(ls-v.begin());
                sets[a].clear();
                sets[a] = v;
            }
        }

    }
    getSets(k + 1, n, sets, arr);
}


void solve(){
    int n;
    cin >> n;
    bool** arr;
    arr = new bool*[n];
    for(int i=0; i<n; i++){
        arr[i] = new bool[n];
    }
    string s;
    for(int i=0; i<n; i++){
        cin >> s;
        for(int j=0; j<n; j++){
            arr[i][j] = bool(s[j] - 48);
        }
    }

    vector<vector<int>>sets;
    for(int i=0; i<n; i++)
        sets.push_back(vector<int>(1, i+1));

    getSets(0, n, sets, arr);

    for(int i=0; i<n; i++){
        cout << sets[i].size() << " ";
        for(int j=0; j<sets[i].size(); j++){
            cout << sets[i][j] << " ";
        }
        cout << endl;
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