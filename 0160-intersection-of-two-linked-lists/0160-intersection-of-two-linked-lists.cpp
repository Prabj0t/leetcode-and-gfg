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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<ListNode*> add;
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        
        while( t1 != NULL){
            add.push_back(t1);
            t1 = t1 -> next;
        }
        while( t2 != NULL ){
            if(find(add.begin() , add.end() , t2) != add.end()){
                return t2;
                break;
            }
            else{
                t2 = t2-> next;    
            }
        }
        return NULL;
    }
};