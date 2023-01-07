#include<iostream>
#include<cmath>
#include<string>
using namespace std;

void solve(){
    unsigned long long int a, b, c, d;
    cin >> a >> b >>c >> d;
    unsigned long long int st = a*b;
    unsigned long long int en = c*d;
    int x=-1, y=-1;
    unsigned long long int mul = 2;
    cout << en << " " << st << endl;
    // exit(0);
    while(st*mul <= en){
        int i = a+1;
        while(i <= c){
            // cout << i << endl;
            if((st*mul)%i == 0){
                if((st*mul)/i <= d && (st*mul)/i > b){
                    x = i;
                    y = (st*mul)/i;
                    cout << x << " " << y << endl;
                    return;
                }
                else if((st*mul)/i <= b){
                    break;
                }
            }
            i++;
        }

        i = b + 1;
        while(i <= d){
            if((st*mul)%i == 0){
                if((st*mul)/i <= c && (st*mul)/i > a){
                    y = i;
                    x = (st*mul)/i;
                    cout << x << " " << y << endl;
                    return;
                }
                else if((st*mul)/i <= a){
                    break;
                }
            }
            i++;
        }
        mul++;
        if(st*mul > en){
            cout << "There" << endl;
        }
    }

    cout << "-1 -1" << endl;
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