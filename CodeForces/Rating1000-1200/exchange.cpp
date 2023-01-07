#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int solve(){
    int a, b, n;
    cin >> n >> a >>b;
    if(a > b){
        return 1;
    }
    else{
        if(n % a == 0){
            return n/a;
        }
        else{
            return n/a + 1;
        }
    }
}

int main()
{
    int t;
    cin>> t;
    for(int i=0; i<t; i++){
       cout <<  solve() << endl; 
    }
    return 0;
}