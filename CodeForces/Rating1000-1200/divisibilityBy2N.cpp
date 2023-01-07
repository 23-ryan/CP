#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int problem(){
    int sz;
    cin>> sz;
    int arr[sz];
    int prod = 1;
    int curr = 0;
    for(int i=0; i<sz; i++){
        cin >> arr[i];
        curr += int(log2(arr[i] & ~(arr[i]-1)));
    }
    int rem = sz - curr;
    if(rem <= 0){
        return 0;
    }
    int maxPow2 = 0;
    for(int i=sz; i>=1; i--){
        if((i & (i-1)) == 0) {
            maxPow2 = int(log2(i & ~(i-1)));
            break;
        }
    }
    int numMoves = 0;
    int pow2[maxPow2 + 1] = {0};

    int k;
    for(int i=1; i<=sz; i++){
        k = int(round(log2(i & ~(i-1))));
        pow2[k]++;
    }
    for(int i=maxPow2; i>=1 && rem >0; i--){
        int m = 0;
        while(m < pow2[i] && rem > 0){
            rem -=i;
            m++;
            numMoves++;
        }
        if(rem <= 0) return numMoves;
    }
    
    return -1;
    

}


int main()
{
    int t;
    cin>> t;
    for(int i=0; i<t; i++){
        cout << problem() << endl;
    }

    return 0;
}