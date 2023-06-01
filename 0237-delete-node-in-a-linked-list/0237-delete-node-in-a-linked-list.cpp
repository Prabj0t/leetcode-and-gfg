/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node){
        ListNode* temp = node;
        ListNode* frd = temp->next;
        while(frd->next != NULL){
            temp->val = frd->val;
            temp = temp -> next;
            frd = temp-> next;
        }
        temp->val = frd->val;
        temp->next = NULL;
    }
};