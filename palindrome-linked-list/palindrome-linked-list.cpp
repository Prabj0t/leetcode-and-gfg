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
//       void insertathead(ListNode *&head, int key)
// {
//     // new node created
//     ListNode *temp = new ListNode(key);
//     temp->next = head;
//     head = temp;
// }
    
ListNode* rev(ListNode* &head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode* chottahead = rev(head->next);
    head->next->next = head;
    head->next = NULL;
    return chottahead;
}

bool isPalindrome(ListNode* head) {
    if( head == NULL || head ->next == NULL){
        return 1;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next ;
        fast = fast-> next->next;
    }
    ListNode* H2 = rev(slow->next);
    ListNode* t1 = head;
    ListNode* t2 = H2;
    while (t1 != NULL && t2 != NULL) {
        if (t1->val != t2->val) {
            return false;
        }
        t1 = t1->next;
        t2 = t2->next;
    }
    return true;
}

};