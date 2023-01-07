#include<iostream>
#include<cmath>
#include<string>
using namespace std;

void solve(){
    long long unsigned int n;
    cin >> n;
    long long unsigned int a, k;
    string s;

    long long unsigned int len1 = 1, len2 = 1;
    long long unsigned int smallest = 0, numSmall = 1;
    long long unsigned int largest = 0, numLarge = 1;
    
    for(int i=0; i<n; i++){
        cin >> a >> k >> s;
        if(a == 1){
            len1+=s.length()*k;
            for(int j=0; j<s.length(); j++){
                if(smallest > (s[j]-'a')){
                    smallest = s[j];
                    numSmall = 1*k;
                } 
                else if(smallest == (s[j] - 'a')){
                    numSmall+=k;
                }
            }
        }
        else if(a == 2){
            len2+=s.length()*k;
            for(int j=0; j<s.length(); j++){
                if(largest < (s[j]-'a')){
                    largest = s[j];
                    numLarge = 1*k;
                } 
                else if(largest == (s[j] - 'a')){
                    numLarge+=k;
                }
            }
        }

        // CONDITION CHECK
        if(smallest < largest){
            cout << "YES" << endl;
        }
        else if(largest == smallest){
            if(len1 == numSmall && numSmall < numLarge){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        else{
            cout << "NO" << endl;
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