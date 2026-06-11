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
            ListNode* nextNode = temp->next;
            temp->next = prev;

            prev = temp;
            temp = nextNode;
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
        ListNode* middleNode = findMiddle(head);
        ListNode* l2Head = middleNode->next;
        middleNode->next = nullptr;

        l2Head = reverseList(l2Head);
        ListNode* temp1 = head;
        ListNode* temp2 = l2Head;

        while(temp1 && temp2){
            ListNode* temp1Next = temp1->next;
            ListNode* temp2Next = temp2->next;

            temp1->next = temp2;
            temp2->next = temp1Next;

            temp1 = temp1Next;
            temp2 = temp2Next;
        }
    }
};
