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
        if( frd != NULL){
            temp->val = frd->val;
            temp-> next = frd -> next;
            frd -> next = NULL;
        }
        else{
            temp = NULL;

        }
                // temp->next = NULL;
        
        // ListNode *nextNode = node->next;
        // // Step 2
        // node->val = nextNode->val;
        // // Step 3
        // node->next = nextNode->next;
        // nextNode->next = nullptr;
        // delete(nextNode);
    }
};