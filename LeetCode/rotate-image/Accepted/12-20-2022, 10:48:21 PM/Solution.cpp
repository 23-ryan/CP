// https://leetcode.com/problems/rotate-image

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       vector<vector<int>> v;
        int l = matrix.size();
        for(int i=0; i<l; i++){
            vector<int> temp;
            for(int j = l-1; j>=0; j--){
                temp.push_back(matrix[j][i]);
            }
            v.push_back(temp);
        }
        for(int i=0; i<l; i++){
            for(int j=0; j<l; j++){
                matrix[i][j] = v[i][j];
            }
        }
    }
};