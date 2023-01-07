// https://leetcode.com/problems/combination-sum

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> dp(target+1);
        vector<int>a(1);

        sort(candidates.begin(), candidates.end());

        for(int i=1; i<=target; i++){
            for(auto j: candidates){
                if(i==j){
                    dp[i].push_back(vector<int>(1, j));
                }
                else if(i-j >= 0 && dp[i-j].size() !=0){
                    vector<vector<int>> toPush = dp[i-j];
                    for(auto vec: toPush){
                        cout << vec.back() << endl;
                        if(vec.back() <= j){
                            vec.push_back(j);
                            dp[i].push_back(vec);
                        }
                    }
                    
                }
            }
        }

        return dp[target];
    }
};