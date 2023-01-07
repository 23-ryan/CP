#include<iostream>
#include<cmath>
#include<string>
using namespace std;

bool problem(){
    int sz;
    cin>> sz;
    int arr[sz];

    bool res = true;    
    for(int i=0; i<sz; i++){
        cin >> arr[i];
    }
    for(int i=0; i< sz; i++){
        if(i != sz - 1 && arr[i] == 1){
            res = !res;
        }
        else{
            return res;
        }
    }
    return res;

}

int main()
{

    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        if(problem()){
            cout << "First" << endl;
        }
        else{
            cout << "Second" << endl;
        }
    }
    return 0;
}