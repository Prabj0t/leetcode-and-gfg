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
      void insertathead(ListNode *&head, int key)
{
    // new node created
    ListNode *temp = new ListNode(key);
    temp->next = head;
    head = temp;
}

    bool isPalindrome(ListNode* head) {
         //Your code here
        ListNode * curr = head;
        ListNode * H2 = new ListNode(curr->val);
        while(curr->next != NULL){
            curr = curr -> next;
            insertathead(H2 ,curr->val);
        }
        ListNode * t1 = head;
        ListNode * t2 = H2;
        while( t1 != NULL && t2 != NULL){
            if ( t1 -> val == t2 -> val ){
                t1 = t1 -> next ;
                t2 = t2 -> next ;
            }    
            else{
                return 0 ;
            }
        }
        return 1;
    }
};