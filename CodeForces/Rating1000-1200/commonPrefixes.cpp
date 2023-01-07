#include<iostream>
#include<cmath>
#include<string>
#include<climits>
#include<random>
using namespace std;


void problem(){
    int sz;
    cin>>sz;
    int arr[sz];
    int ma=INT_MIN;
    for(int i=0; i<sz; i++){
        cin>>arr[i];
        ma = max(ma, arr[i]);
    }
    if(ma == 0) ma = 2;
    string str(ma ,'a');
    cout << str << endl;
    for(int i=0; i<sz; i++){
        for(int j=arr[i]; j<ma; j++){
            str[j] = char(((str[j]- 97)+1)%26 + 97);
        }
        cout << str << endl;
    }
}


int main()
{
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        problem();
    }

    return 0;
}