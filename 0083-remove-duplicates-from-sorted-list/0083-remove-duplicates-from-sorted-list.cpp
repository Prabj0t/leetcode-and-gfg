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
    ListNode* deleteDuplicates(ListNode* head) {
        if ( head == NULL){
            return head;
        }
        ListNode* a = head;
        ListNode* b = head;
        while (b -> next != NULL ){
            b = a-> next;
            if ( a->val == b->val){
                a-> next = b -> next ;
                b->next = NULL;
                b = a;
            }
            else{
            a = a-> next;}
        }
        

    return head;
    }
};