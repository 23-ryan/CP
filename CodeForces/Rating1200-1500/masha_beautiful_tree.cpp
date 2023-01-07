#include<iostream>
#include<cmath>
#include<string>
using namespace std;


class Node{
    public:
    int val;
    Node* left, *right;

    Node(){
        val = -1;
        left = nullptr;
        right = nullptr;
    }

    Node(int val){
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

void insert(Node* root, int h, int i){
    if(h == i){
        cin >> root->val;
    }
    else{
        root->left = new Node();
        root->right = new Node();
        insert(root->left, h, i+1);
        insert(root->right, h, i+1);
    }
}

void getMinMoves(Node* node, int i, int h, int& moves){
    if(moves == -1) return;

    // RECCURSE
    if(i != h-1){
        getMinMoves(node->left, i+1, h, moves);
        getMinMoves(node->right, i+1, h, moves);    
    }

    // CHECKING FOR THE CONDITION OF BEAUTIFUL TREE!!
    if(abs(node->left->val - node->right->val) != (unsigned long long int)(pow(2, (h-1-i)))){
        moves = -1;
        return;
    }

    // MAKING THE MOVE AND UPDATING THE VALUE OF THE PARENT NODE
    if(node->left->val > node->right->val){
        int a = node->left->val;
        node->left->val = node->right->val;
        node->right->val = a;
        node->val = max(node->right->val, node->left->val);
        moves += 1;
    }
    else{
        node->val = max(node->right->val, node->left->val);
    }
}

void solve(){
    int m;
    cin >> m;
    Node* root = new Node();
    int h = int(log2(m));
    insert(root, h, 0);

    if(h == 0){
        cout << 0 << endl;
        return;
    }

    int moves=0;
    getMinMoves(root, 0, h, moves);
    cout << moves << endl;
}

int main()
{
    int t;
    cin >>t;
    for(int i=0; i<t; i++){
        solve();
    }

    return 0;
}