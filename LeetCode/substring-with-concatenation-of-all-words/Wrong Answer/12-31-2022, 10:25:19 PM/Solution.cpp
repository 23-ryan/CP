// https://leetcode.com/problems/substring-with-concatenation-of-all-words

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> arr;
        vector<int> ans;
        int l = s.size();
        int k = words[0].length();
        int w = words.size();
        for(int i=0; i<w; i++){
            arr[words[i]]++;
        }

        for(int i=0; i<l; i++){
            if(arr[s.substr(i, k)] != 0){
                unordered_map<string, int> grr;
                int j = i;
                // cout << arr[s.substr(j, k)] << endl;
                int num = 0;
                while(num < w && j < l-k && arr[s.substr(j, k)] != 0){
                    grr[s.substr(j, k)]++;
                    j+=k;
                    num++;
                }
                bool tell = true;
                for(auto j:arr){
                    if(arr[j.first] != grr[j.first]){
                        cout << i << j.first << arr[j.first] << grr[j.first] << endl;
                         tell = false;
                         break;
                    }
                }
                // cout << i << endl;
                if(tell){
                    ans.push_back(i);
                }
                i+=k;
                i--;
            }
        }
        return ans;
    }
};