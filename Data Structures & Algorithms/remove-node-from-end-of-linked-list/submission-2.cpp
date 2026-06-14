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
        ListNode* dummy= new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        int ctr = 0;
        while(fast && ctr != n){
            ++ctr;
            fast = fast->next;
        }

        while(fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* nextNode = slow->next;
        slow->next = nextNode->next;
        delete nextNode;

        return dummy->next;
    }
};
