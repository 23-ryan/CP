#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    long long unsigned int s, n;
    cin >> n >> s;
    vector<long long unsigned int>v(n);

    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    long long int b = n-1;
    long long unsigned int time = 0;
    while(v[b] == s){
        time += (v[b] + 1);
        b--;
    }
    // cout << "INITIAL" << time << endl;
    long long int big = b;
    long long unsigned int aSpace = 0;
    long long unsigned int bSpace = 0;
    long long int a = 0;
    long long unsigned int extraTime = 0;
    while(b>=a){
        if(s - aSpace >= v[b]){
            bSpace = v[b];
            aSpace = 0;
            // cout<< "B" << b << endl;
            b--;
            if(a > b){
                extraTime++;
                continue;
            }
        }
        else{
            extraTime++;
            aSpace = 0;
            continue;
        }

        if(s - bSpace >= v[a]){
            aSpace = v[a];
            bSpace = 0;
            // cout<< "A" << a << endl;
            a++;
            
        }
        else{
            extraTime++;
            bSpace = 0;
            continue;
        }

        if(a > b){
            extraTime++;
        }
    }
    // extraTime++; // FOR THE LAST ONE MINUTE.

    for(int i=0; i<=big; i++){
        time+=v[i];
    }
    time += extraTime;
    cout << time << endl;
    
    return 0;
}