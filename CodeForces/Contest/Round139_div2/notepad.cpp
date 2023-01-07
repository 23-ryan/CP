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


class Node{
    public:
        int val;
        bool arr[26] = {0};
        Node(){
            this->val = -1;
        }
};

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    Node arr[26];
    for(int i=0; i<26; i++){
        arr[i].val = i;
    }
    unordered_map<char, bool> ch;

    for(int i=0; i<n-1; i++){
        if(ch[s[i]-'a'] == 0){
            arr[s[i]-'a'].arr[s[i+1] - 'a'] = true;
            ch[s[i]-'a'] = true;
            if(i+2 < n){
                if(s[i] == s[i+1] && s[i+1] == s[i+2]){
                    i = i+1;
                }
            }
        }
        else{
            if(arr[s[i]-'a'].arr[s[i+1]-'a'] == true){
                cout << "YES" << endl;
                return;
            }
            else{
                arr[s[i]-'a'].arr[s[i+1]-'a'] = true;
                if(i+2 < n){
                    if(s[i] == s[i+1] && s[i+1] == s[i+2]){
                        i = i+1;
                    }
                }
            }
        }
    }
    cout << "NO" << endl;
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