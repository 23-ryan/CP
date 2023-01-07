#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<bitset>
#include<climits>

using namespace std;

# define itn int
# define LOG(x) cout << x << endl

typedef long long ll;

void solve(){
    
}

vector<int> twoSum(vector<int>& nums, int target) {
        int l = nums.size();
        vector<bool> dp(target, 0);
        
        vector<int> ans;
        for(auto i : nums){
            if(i < target)
                dp[i-1] = true;
        }
        
        for(int i=0; i<l; i++){
            if(target - nums[i] - 1 < target && dp[target - nums[i] - 1] == true){
                for(int j=0; j<l; j++){
                    if(target - nums[i] == nums[j] && i != j){
                        ans.push_back(i);
                        ans.push_back(j);
                        return ans;
                    }
                }
            }
        }
        return ans;
    }

int main()
{
    vector<int>v = {2, 7, 11, 15};
    vector<int> ans = twoSum(v, 9);
    for(auto i: ans){
        cout << i << " ";
    }
    LOG("");
}