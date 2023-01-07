#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Node{
    public:
    int value;
    vector<int> adjacency;
    vector<int> weights;
    Node(int val){
        value = val;
    }
    Node(){
        value = -1;
    }
    void addNeigh(Node neigh, int w){

        adjacency.push_back(neigh.value);
        weights.push_back(w);
    }
};

void doDFS(int start, int end, Node arr[], vector<int> &xorArr, bool visited[]){
    if(start == end) return;
    visited[start-1] = 1;
    int l = arr[start-1].adjacency.size();
    for(int i=0; i<l; i++){
        if(!visited[arr[start-1].adjacency[i]-1]){
            xorArr[arr[start-1].adjacency[i]-1] = (arr[start-1].weights[i] ^ xorArr[start-1]);
            doDFS(arr[start-1].adjacency[i], end, arr, xorArr, visited);
        }
    }
}

void solve(){
    int n, a, b;
    cin >> n >> a >> b;
    Node arr[n];
    for(int i=0; i<n; i++){
        arr[i].value = i+1;
    }

    int x, y, w;
    for(int i=0; i<n-1; i++){
        cin >> x >> y >> w;
        arr[x-1].addNeigh(arr[y-1], w);
        arr[y-1].addNeigh(arr[x-1], w);
    }
    vector<int> srcXor(n, -1);
    srcXor[a-1] = 0;
    vector<int> destXor(n, 0);
    destXor[b-1] = 0;

    bool visited[n] = {0};
    doDFS(a, b, arr, srcXor, visited);

    for(int i=0; i<n; i++){
        visited[i] = 0;
    }
    doDFS(b, -1, arr, destXor, visited);
    // for(int i=0; i<n; i++){
    //     cout << srcXor[i] << " " << i+1 << endl;
    // }
    // cout << "-----" << endl;
    // for(int i=0; i<n; i++){
    //     cout << destXor[i] << " " << i+1 << endl;
    // }
    for(int i=0; i<n; i++){
        if(srcXor[b-1] == 0){
            cout << "YES" << endl;
            return;
        }
        else if(i+1 != b && srcXor[i] != -1){
            vector<int>::iterator it = find(destXor.begin(), destXor.end(), srcXor[i]);
            if(it != destXor.end()){
                if(it-destXor.begin() + 1 != b){
                    cout << "YES" << endl;
                    return ;
                }
            }
        }
    }
    cout << "NO" << endl;

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