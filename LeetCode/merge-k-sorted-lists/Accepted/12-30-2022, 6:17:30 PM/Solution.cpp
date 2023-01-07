// https://leetcode.com/problems/merge-k-sorted-lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int l = lists.size();
        ListNode* merged =  nullptr;
        ListNode* toRet;

        bool run = true;
        while(run){
            run = false;
            for(auto list : lists){
                if(list != nullptr) {
                    run = true;
                    break;
                }
            }
            int minElem = INT_MAX;
            int minInd;
            for(int i=0; i<l; i++){
                if(lists[i] != nullptr && lists[i]->val < minElem){
                    minElem = lists[i]->val;
                    minInd = i;
                }
            }
            if(minElem != INT_MAX){
                if(merged == nullptr){
                    merged = new ListNode(lists[minInd]->val);
                    toRet = merged;
                }
                else{
                    merged->next = new ListNode(lists[minInd]->val);
                    merged = merged->next;
                }
                lists[minInd] = lists[minInd]->next;
            }
            else{
                break;
            }
        }
        return toRet;
    }
};