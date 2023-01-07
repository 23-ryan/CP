// https://leetcode.com/problems/swap-nodes-in-pairs

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
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        ListNode* toRet = head;
        while(temp != nullptr && temp->next != nullptr){
            ListNode* store = temp->next;
            if(prev != nullptr){
                prev->next = temp->next;
            }
            else{
                toRet = temp->next;
            }
            temp->next = temp->next->next;
            store->next = temp;
            prev = temp;
            temp = temp->next;
        }
        return toRet;
    }
};