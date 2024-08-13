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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL){
            return head;
        }
        
        int cnt = 0;
        ListNode* temp = head;
        while(temp != NULL){
            cnt++;
            temp = temp->next; 
        }
        
        if( cnt < k){
            return head;
        }
        
        ListNode* curr = head;
        ListNode* nxt = NULL;
        ListNode* prev = NULL;
        
        int reversedCnt = 0;
        while( curr != NULL && reversedCnt < k){
            nxt = curr -> next;
            curr->next = prev;
            reversedCnt++;
            prev = curr;
            curr = nxt;
        }
        
        if(nxt != NULL){
            head->next = reverseKGroup(nxt , k);
        }
        
        return prev;
    }
};