// https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int maxPre = 0;
        char word;
        bool stop = false;
        while(!stop){
            word = strs[0][maxPre];
            for(auto i : strs){
                if(i[maxPre] != word || maxPre == i.length()){
                    stop = true;
                    break;
                }
            }
            if(!stop) maxPre++;
        }
        cout << maxPre << endl;
        return strs[0].substr(0, maxPre);
        
        

    }
};