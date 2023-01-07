#include<iostream>
#include<cmath>
#include<string>
#include<map>
using namespace std;

void problem(){
    int n, k;
    cin >> n >> k;

    map<int, int> arr;
    map<int, int> grr;
    int in;
    for(int i=0; i<n; i++){
        cin >> in;
        if(arr.find(in) == arr.end()){
            arr[in] = i;
            grr[in] = i;
        }
        else{
            grr[in] = max(i, grr.at(in));
        }
    }
    int a, b;
    for(int i=0; i<k; i++){
        cin >> a >> b;
        try{
            if(arr.at(a) < grr.at(b)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        catch(std::out_of_range& e){
            cout << "NO" << endl;
        }
        
    }

}


int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        problem();
    }
    return 0;
}