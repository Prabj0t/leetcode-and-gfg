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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp = new ListNode();
        ListNode* a = list1;
        ListNode* res= temp;
        ListNode* b = list2;
        while(a != NULL && b != NULL){
            if( a->val <= b->val){
                res->next = a;
                res = res->next;
                a = a-> next;
            }
            else{
                res->next = b;
                res = res->next;
                b = b->next;
                }
        }
        if(a == NULL){
            res->next = b;
        }
        if(b == NULL){
            res->next = a;
        }
        res = temp->next;
        return res;
    }
};