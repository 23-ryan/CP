// https://leetcode.com/problems/remove-nth-node-from-end-of-list

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int l = 0;
        while(temp != nullptr){
            temp = temp->next;
            l++;
        }
        // cout << l-n-1 << endl;
        int i = 0;
        temp = head;
        while(i < l-n-1){
            temp = temp->next;
            i++;
        }
        // cout << temp->val;
        if(l-n-1 < 0){
            head = head->next;
        }
        else{
            temp->next = temp->next->next;
        }
        return head;
    }
};