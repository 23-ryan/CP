#include<iostream>
#include<cmath>
#include<string>
using namespace std;


int problem(){
    int sz;
    cin>> sz;
    if(sz == 0){
        return 0;
    }
    int arr[sz];

    for(int i=0; i<sz; i++){
        cin>> arr[i];
    }
    int st=0, end=sz-1;

    int numRem = 0;
    while(st != end){
        if(arr[st+1] >= arr[st]) st++;
        else if(arr[end] <= arr[end-1]) end--;
        else{
            numRem = (++st);
        }
    }

    return numRem;
    return -1;
}


int main()
{
    int t;
    cin>> t;
    int soln[t];
    for(int i=0; i<t; i++){
        soln[i] = problem();
    }
    for(int i=0; i<t; i++){
        cout << soln[i] << endl;
    }
    return 0;
}