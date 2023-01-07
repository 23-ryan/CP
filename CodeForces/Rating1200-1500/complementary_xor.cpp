#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

void flip(int &n, int l, int r){
    for(int i=r; i<=l; i++){
        n = n^(1<<i);
    }
}

bool getBit(int n, int i){
    return n & (1 << i);
}

int invertbit(int n, int l){
    for(int i=0; i<l; i++)
        n = n^(1<<i);

    return n;
}

void solve(){
    int n;
    cin>>n;
    string a;
    string b;
    cin >> a >> b;

    const int l = a.length();
    int n1 = 0;
    for(int i=1; i<=l ;i++){
        if(a[l - i] == '1'){
            n1+=(1<<(i-1));
        }
    }
    int n2 = 0;
    for(int i=1; i<=l; i++){
        if(b[l - i] == '1'){
            n2+=(1<<(i-1));
        }
    }

    // cout << "----------" << endl;
    // cout << bitset<8>(n1^n2).to_string() << " " << (n1^n2) << endl;
    // cout << bitset<8>(invertbit(n1^n2, l)).to_string()<<  " " << invertbit(n1^n2, l) << endl;
    // cout << "----------" << endl;

    if((n1^n2) != 0 && invertbit(n1^n2, l) != 0){
        cout << "NO" << endl;
        return;
    }
    else{
        int num = 0;
        vector<int>seq1;
        vector<int>seq2;
        for(int i=0; i<a.length(); i++){
            if(bool((1 << i) & n1)){
                flip(n1, a.length()-1, i);
                seq1.push_back(1);
                seq2.push_back(a.length() - i);
                if(i != 0){
                    flip(n2, i-1, 0);
                }
            
            }
        }


        if(n1^n2 != 0){
            // 000 111 --> type strings

            flip(n1, 0, 0);
            seq1.push_back(a.length());
            seq2.push_back(a.length());
            flip(n2, a.length()-1, 1);

            // 001 001
            flip(n1, a.length()-1, 0);
            seq1.push_back(1);
            seq2.push_back(a.length());

            // 110 001
            flip(n1, a.length()-1, 1);
            flip(n2, 0, 0);
            seq1.push_back(1);
            seq2.push_back(a.length()-1);

            // 000 000
            // :)
        }
        
        // MIGHT CAUSE CONFUSION BECAUSE I AM USING THE DYNAMIC LENGTHS OF THESE STRINGS/BITSETS
        
        cout << "YES" << endl;
        cout << seq1.size() << endl;
        for(int i=0; i<seq1.size(); i++){
            cout << seq1[i] << " " << seq2[i] << endl;
        }
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