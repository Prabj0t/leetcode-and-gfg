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
    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* smallHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return smallHead;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        
        ListNode* reversed = reverse(head);
        int i = 0;
        ListNode* prev = NULL;
        ListNode* temp = reversed;
        while (i < n - 1 && temp != NULL) {
            prev = temp;
            temp = prev->next;
            i++;
        }
        
        if (prev == NULL) {
            reversed = reversed->next;
        } else {
            prev->next = temp->next;
        }
        
        temp->next = NULL;
        ListNode* headAns = reverse(reversed);
        return headAns;
    }
};
