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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* even = NULL;
        ListNode* eventail = NULL;
        ListNode* odd = NULL;
        ListNode* oddtail = NULL;
        int i = 0;
        while(head != NULL){
            if(i == 0){
                if(odd == NULL){
                    odd = head;
                    oddtail = head;
                }
                else {
                    oddtail->next = head;
                    oddtail = oddtail->next;
                }
                 i = 1;
            }
            else{
                if(even == NULL){
                    even = head;
                    eventail = head;
                }
                else {
                    eventail->next = head;
                    eventail = eventail->next;
                   
                }
                 i = 0;
            }
            head = head->next;
                
        }
        
        if(eventail != NULL){
            eventail->next = NULL;
        }
        if(odd != NULL)
            oddtail->next = even;
        return odd;
    }
};