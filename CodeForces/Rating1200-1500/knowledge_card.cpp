#include<iostream>
#include<cmath>
#include<string>
#include<cassert>
using namespace std;

void solve(){
    int n, m, k;
    cin >> n >>m >>k;
    int arr[k] = {0};
    int maxNum = k;
    int chkNum = (n*m)-3;

    int cnt = 0;
    bool grr[k] = {0};

    for(int i=0; i<k; i++)
        cin >> arr[i];

    for(int i=0; i<k; i++){
        if(cnt == chkNum){
            cout << "TIDAK" << endl;
            return;
        }
        if(arr[i] == maxNum){
            cnt++;
            grr[maxNum-1] = 1;
            while(grr[maxNum - 1] != 0){
                maxNum--;
                cnt--;
                if(maxNum == 0) break;
            }
            continue;
        }
        grr[arr[i]-1] = 1;
        cnt++;
    }
    assert(cnt == 0);
    cout << "YA" << endl;

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