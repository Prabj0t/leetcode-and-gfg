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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int count = 0 ;
        while(temp != NULL){
            temp = temp->next;
            ++count;
        }
        if( count == n ){
            ListNode* nvahead = head->next;
            delete head;
            return nvahead;
        }
        
        temp = head;
        int i = 0;
        while(i < count - n -1 && temp != NULL){
            temp = temp -> next;
            i++;
        }
        temp -> next = temp->next -> next;
        return head;
    }
};