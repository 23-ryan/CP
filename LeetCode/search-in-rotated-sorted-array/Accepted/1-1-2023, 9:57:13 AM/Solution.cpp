// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = nums.size();
        int chkPt = -1;
        int st = 0, en = l-1;
        int ans = -1;
        if(l == 2){
            if(nums[0] == target) ans = 0;
            else if(nums[1] == target) ans = 1;
        }
        else if(l == 1){
            if(nums[0] == target) ans = 0;
        }
        else if(nums[0] > nums[l-1]){
            while(st <= en){
                int mid = st + (en-st)/2;
                // cout << mid << st << en << endl;
                if(mid == 0 && nums[mid] > nums[l-1] && nums[mid] > nums[mid+1]){
                    chkPt = mid;
                    break;
                }
                else if(mid == l-1 && nums[mid] > nums[0] && nums[mid] > nums[mid-1]){
                    chkPt = mid;
                    break;
                }
                else if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                    chkPt = mid;
                    break;
                }
                else if(nums[mid] < nums[mid-1] && nums[mid] < nums[mid+1]){
                    chkPt = mid-1;
                    break;
                }
                    
                if(nums[mid] > nums[0] && nums[mid] > nums[l-1]){
                    st = mid+1;
                    // cout << st << mid << endl;
                }
                else if(nums[mid] < nums[0] && nums[mid] < nums[l-1]) en = mid-1;
                
            }
        }
        cout << chkPt << endl;

        if(ans == -1){
            if(chkPt != -1){
                if(target <= nums[chkPt] && target >= nums[0]){
                    st = 0;
                    en = chkPt;
                }
                else if(target >= nums[chkPt+1] && target <= nums[l-1]){
                    st = chkPt+1;
                    en = l-1;
                }
            }
            
            while(st <= en){
                int mid = (st+en)/2;
                if(nums[mid] == target){
                    ans = mid;
                    break;
                }
                else if(nums[mid] > target) en = mid-1;
                else st = mid+1;
            }
        }
        return ans;
    }
};