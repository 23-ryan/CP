// https://leetcode.com/problems/merge-two-sorted-lists

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* merged = nullptr;
        ListNode* toRet = nullptr;
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val <= list2->val){
                if(merged == nullptr){
                    merged = new ListNode(list1->val);
                    toRet = merged;
                }
                else{
                    merged->next = new ListNode(list1->val);
                    merged = merged->next;
                }
                list1 = list1->next;
            }
            else if(list1->val > list2->val){
                if(merged == nullptr){
                    merged = new ListNode(list2->val);
                    toRet = merged;
                }
                else{
                    merged->next = new ListNode(list2->val);
                    merged = merged->next;
                }
                list2 = list2->next;
            }
        }
        while(list1 != nullptr){
            if(merged == nullptr){
                merged = new ListNode(list1->val);
                toRet = merged;
            }
            else{
                merged->next = new ListNode(list1->val);
                merged = merged->next;
            }
            list1 = list1->next;
        }
        while(list2 != nullptr){
            if(merged == nullptr){
                merged = new ListNode(list2->val);
                toRet = merged;
            }
            else{
                merged->next = new ListNode(list2->val);
                merged = merged->next;
            }
            list2= list2->next;
        }

        return toRet;
    }
};