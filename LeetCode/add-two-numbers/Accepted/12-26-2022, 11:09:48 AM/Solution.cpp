// https://leetcode.com/problems/add-two-numbers

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int value = 0;
        ListNode* ans = nullptr;
        ListNode* ptr;
        while(l1 != nullptr && l2 != nullptr){
            value = (l1->val + l2->val + carry)%10;
            carry = (l1->val + l2->val + carry)/10;
            if(ans == nullptr){
                ans = new ListNode(value);
                ptr = ans;
            }
            else{
                ans->next = new ListNode(value);
                ans = ans->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != nullptr){
            value = (l1->val + carry)%10;
            carry = (l1->val + carry)/10;
            ans->next = new ListNode(value);
            ans = ans->next;
            l1 = l1->next;
        }
        while(l2 != nullptr){
            value = (l2->val + carry)%10;
            carry = (l2->val + carry)/10;
            ans->next = new ListNode(value);
            ans = ans->next;
            l2 = l2->next;
        }
        if(carry != 0){
            ans->next = new ListNode(carry);
        }
        return ptr;
    }
};