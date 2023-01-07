#include<iostream>
#include<cmath>
#include<string>
using namespace std;


// use basic number theory kp + kq = n ==> k(p + q) = n ==> p + q = n/k, where p, q are co-prime now you just have to find the least divisor of n and you will be able to find the two numbers a, #include<iostream>
// Also to improve the time complexity you can simply use the sqrt property to get the least divisor

#include<cmath>
#include<string>
using namespace std;
int main()
{
    return 0;
}


void solve(){
    int n;
    cin >> n;
    int i=2;
    while(i*i <= n){
        // cout << i << endl;
        if(n%i == 0){
            cout << n/i << " " << n - n/i << endl;
            return;
        }
        i++;
    }
    cout << 1 << " " << n-1 << endl;
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