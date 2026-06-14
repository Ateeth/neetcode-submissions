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

    ListNode* reverseList(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while(temp){
            ListNode* tempNext = temp->next;
            temp->next = prev;

            prev = temp;
            temp = tempNext;
        }

        return prev;
    }

    ListNode* findMiddle(ListNode* head){
        ListNode* fast = head->next;
        ListNode* slow = head;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
    void reorderList(ListNode* head) {
        ListNode* middle = findMiddle(head);
        ListNode* revL2Head = reverseList(middle->next);
        ListNode* temp = head; 
        ListNode* temp2 = revL2Head;
        middle->next = nullptr;

        while(temp && temp2){
            ListNode* l1Next = temp->next;
            ListNode* l2Next = temp2->next;

            temp->next = temp2;
            temp2->next = l1Next;

            temp = l1Next;
            temp2 = l2Next;
        }
    }
};
