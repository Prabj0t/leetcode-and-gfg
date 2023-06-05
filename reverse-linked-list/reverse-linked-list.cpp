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

ListNode* rev(ListNode* head){
    if(head == NULL || head->next == NULL){
    return head;
    }
    else{

        ListNode* temp = rev(head->next);
            head->next->next = head;
            head->next = NULL;
        return temp;
    }
}
public:
    ListNode* reverseList(ListNode* head) {
        // ListNode* prev = NULL ;
        // ListNode* cur = head;

        // while(cur != NULL){
        //     ListNode* fwd = cur->next;
        //     cur->next = prev;
        //     prev = cur;
        //     cur = fwd;

        // }
        // return prev;
        return rev(head);
        }
};