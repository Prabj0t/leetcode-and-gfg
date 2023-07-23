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
    ListNode* rev(ListNode* &head){
        if(head == NULL || head->next == NULL){
            return head;
        }
    
        
        ListNode* chotahead = rev( head->next);
        head->next -> next = head;
        head->next = NULL;
        
        return chotahead;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if (head == nullptr || head->next == nullptr || left == right) {
            return head;
        }
        
        ListNode* temp = head;
        ListNode* prev = NULL;
        
        
        for(int i = 0 ; i < left-1 ; i++){
            prev = temp;
            temp = temp->next; 
        }
        
        if (temp == nullptr) {
            // 'left' position is beyond the end of the list
            return head;
        }
        
        ListNode* leftNode = temp;
        ListNode* rightNode = temp; 
        
        // Move temp to the node at position right+1
        for (int i = 0; i < right - left; i++) {
           temp = temp->next;
        }
        
        if (temp != nullptr) {
            rightNode = temp->next;
            temp->next = nullptr;
        }

        // Reverse the sublist from leftNode to rightNode
        leftNode = rev(leftNode);

        // Connect the reversed sublist back to the original list
        if (prev != nullptr) {
            prev->next = leftNode;
        } 
        else {
            head = leftNode;
        }

        while (leftNode->next != nullptr) {
            leftNode = leftNode->next;
        }
        
        leftNode->next = rightNode;
        return head;
    }
};