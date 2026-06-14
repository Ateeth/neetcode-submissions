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
        ListNode* t1 = l1;
        ListNode* t2 = l2;

        int carry = 0;
        ListNode* dummy = new ListNode(0, nullptr);
        ListNode* curr= dummy;

        while(t1 || t2){            
            if(t1){
                carry += t1->val;
                t1 = t1->next;
            }

            if(t2){
                carry += t2->val;
                t2 = t2->next;
            }

            curr->next = new ListNode(carry%10);
            carry = carry / 10;
            curr = curr->next;
        }

        if(carry != 0){
            curr->next = new ListNode(carry);
        }

        return dummy->next;
    }
};
