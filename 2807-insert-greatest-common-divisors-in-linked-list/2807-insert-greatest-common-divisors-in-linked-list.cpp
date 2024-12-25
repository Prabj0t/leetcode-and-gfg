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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* prev = head;
        while(prev->next!= NULL){
            ListNode* curr = prev->next;
            
            int mini = min(prev->val , curr->val);
            while(prev->val%mini != 0 || curr->val%mini != 0){
                mini--;
            }
            
            if(prev->val%mini == 0 && curr->val%mini == 0){
                ListNode* temp = new ListNode(mini);
                temp->next = curr;
                prev->next = temp;
            }
            prev = prev->next;
            if(prev != NULL){
                prev = prev->next;
            }
        }
        return head;
    }
};