#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void getLosion(int &green, int &blue, long long unsigned int &power, int choice){
    if(choice == 1){
        if(green > 0){
            green--;
            power = power*2;
        }
        else if(blue >0){
            blue--;
            power = power*3;
        }
    }
    else if(choice == 2){
        if(green > 1){
            green--;
            power = power*2;
        }
        else if(blue > 0){
            blue--;
            power = power*3;
        }
        else if(green >0){
            green--;
            power = power*2;
        }
    }
    else if(choice == 3){
        if(blue > 0){
            blue--;
            power = power*3;
        }
        else if(green > 0){
            green--;
            power = power*2;
        }
    }
}

void solve(){
    int n;
    long long unsigned int poow;
    cin >> n >> poow;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>> v[i];
    }
    sort(v.begin(), v.end());
    long long unsigned int power = poow;
    int green = 2, blue = 1; 
    int numEaten = 0;
    int finalEaten = 0;
    for(int i=0; i<n; i++){
        if(power > v[i]){
            power += v[i]/2;
            numEaten++;
        }
        // SEQ 1
        else{
            while(power <= v[i]){
                if(green == 0 & blue == 0) break;
                getLosion(green, blue, power, 1);
            }
            if(power <= v[i]) break;
            else{
                power = power + v[i]/2;
                numEaten++;
            }
        }
        
    }
    finalEaten = max(finalEaten, numEaten);

    numEaten = 0;
    blue = 1, green = 2;
    power = poow;
    for(int i=0; i<n; i++){
        if(power > v[i]){
            power += v[i]/2;
            numEaten++;
        }
        // SEQ 1
        else{
            while(power <= v[i]){
                if(green == 0 & blue == 0) break;
                getLosion(green, blue, power, 2);
            }
            if(power <= v[i]) break;
            else{
                power = power + v[i]/2;
                numEaten++;
            }
        }
        
    }

    finalEaten = max(finalEaten, numEaten);

    numEaten = 0;
    blue = 1, green = 2;
    power = poow;
    for(int i=0; i<n; i++){
        if(power > v[i]){
            power += v[i]/2;
            numEaten++;
        }
        // SEQ 1
        else{
            while(power <= v[i]){
                if(green == 0 & blue == 0) break;
                getLosion(green, blue, power, 3);
            }
            if(power <= v[i]) break;
            else{
                power = power + v[i]/2;
                numEaten++;
            }
        }
        
    }
    finalEaten = max(finalEaten, numEaten);

    cout << finalEaten << endl;
}

int main()
{
    int t;
    cin>> t;
    for(int i=0; i<t; i++){
        solve();
    }
    return 0;
}