#include<iostream>
#include<cmath>
#include<string>
#include<vector>
using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> v1;
    vector<int> v2;
    int numDraws = 0;
    bool s = true;
    for(int i=0; i<n; i++){
        if(i == n-1){
            if(a == b && v1.size() != 0){
                if(a == 0){
                    v1.push_back(a);
                    v2.push_back(b);
                    numDraws++;
                }
                else{
                    v1[0]+=1;
                    a--;
                    v1.push_back(a);
                    v2.push_back(b);
                }
            }

            else{
                v1.push_back(a);
                v2.push_back(b);
                if(a==b)
                numDraws++;
            }
        }
        else if(a!=0 || b!=0){
            if(a!=0 && (s || b==0)){
                v1.push_back(1);
                v2.push_back(0);
                a--;
                s = false;
            }
            else if(b!=0 && (!s || a==0)){
                v1.push_back(0);
                v2.push_back(1);
                b--;
                s = true;
            }
        }
        else{
            v1.push_back(0);
            v2.push_back(0);
            numDraws++;
        }
    }

    cout << numDraws << endl;
    for(int i=0; i<v1.size(); i++){
        cout << v1[i] << ":" << v2[i] << endl;
    }

    return 0;
}