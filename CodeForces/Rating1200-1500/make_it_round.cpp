#include<iostream>
#include<cmath>
#include<string>
using namespace std;

long long unsigned int solve(){
    int n, m;
    cin>> n>>m;
    long long unsigned int cnt2 = 0;
    long long unsigned int cnt5 = 0;
    long long unsigned int temp = n;
    while(temp >0){
        if(temp%2 == 0){
            cnt2++;
            temp /= 2;
        }
        else{
            break;
        }
    }
    temp = n;
    while(temp >0){
        if(temp%5 == 0){
            cnt5++;
            temp = temp/5;
        }
        else{
            break;
        }
    }
    long long unsigned int k = 1;
    while(cnt2 < cnt5 && k*2 <= m){
        k*=2;
        cnt2++;
    }
    while(cnt5 < cnt2 && k*5 <= m){
        k*=5;
        cnt5++;
    }
    while(k*10 <= m){
        k*=10;
    }

    long long unsigned int mul = 2;
    while(k*mul <= m){
        mul++;
    }
    long long unsigned int ans = n*k*(mul-1);
    return ans;
}

int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        cout << solve() << endl;
    }
    return 0;
}