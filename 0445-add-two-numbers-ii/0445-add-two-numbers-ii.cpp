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
    ListNode* rev(ListNode* &head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* chotahead = rev(head->next);
        head->next->next = head;
        head->next = NULL;
        return chotahead;
        
    }
    ListNode* addTwoNumbers(ListNode* &l1, ListNode* &l2) {
        
        l1 = rev(l1);
        l2 = rev(l2);
        ListNode* nhead = new ListNode(-1);
        ListNode* temp = nhead;
        int carry = 0;
        int sum = 0;
        while(l1 || l2 || carry){
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;;
            carry = sum/10;
            sum = sum%10;
            ListNode* n = new ListNode(sum);
            temp->next = n; 
            temp = temp->next;
            
//             reset the sum 
            sum = 0; 
        }
        
        // temp->next == NULL;
        
        return rev(nhead->next);
        
    }
};