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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if( head == NULL || head-> next == NULL || k == 0){
            return head;
        }
        
        ListNode* temp = head;
        int size = 1;
        while(temp->next != NULL){
            temp = temp -> next;
            size++;
        }
    
        k = k %  size;
        if( k == 0){
            return head;
        }
        
        int i = 0;
        ListNode* tail = head;
        while(i < size - k - 1)
        {
            tail = tail -> next;
            i++;
        }
        ListNode* newhead = tail -> next;
        tail->next = NULL;
        temp -> next = head;
        return newhead;
    }
        
};










// if( head == NULL || head-> next == NULL){
//             return head;
//         }
        
//         ListNode* temp = head;
//         ListNode* prev = NULL;
//         int size = 1;
//         while(temp->next != NULL){
//             temp = temp -> next;
//             size++;
//         }
//         int i = 1;
//         if(size < k)
//         {
//             int i = 1;
//             while(i <= k)
//             {
//                 ListNode* temp = head;
//                 ListNode* prev = NULL;

//                 while(temp->next != NULL){
//                     prev = temp; 
//                     temp = temp -> next;
//             }

//                 temp->next = head;
//                 prev->next = NULL;
//                 head = temp;
//                 prev = NULL;
//                 i++;
//             }
//         }
//         else
//         {
//             temp->next = head;
//             ListNode* t = head;

//             int i = 0;
//             while( i < size-k-1 ){
//                 t = t-> next;
//                 i++;
//             }
//             head = t -> next;
//             t->next = NULL;
//         }
//         return head;
    