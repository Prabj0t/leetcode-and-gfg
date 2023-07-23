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
    // Helper function to reverse a linked list in place.
    ListNode* rev(ListNode* &head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
    
        ListNode* chotahead = rev(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return chotahead;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || head->next == nullptr || left == right) {
            return head;
        }
        
        ListNode* temp = head;
        ListNode* prev = NULL;
        
        // Move 'temp' and 'prev' pointers to the nodes at positions left-1 and left respectively.
        for (int i = 0; i < left - 1; i++) {
            prev = temp;
            temp = temp->next; 
        }
        
        if (temp == nullptr) {
            // 'left' position is beyond the end of the list.
            return head;
        }
        
        ListNode* leftNode = temp;
        ListNode* rightNode = temp; 
        
        // Move 'temp' pointer to the node at position right.
        for (int i = 0; i < right - left; i++) {
            temp = temp->next;
        }
        
        if (temp != nullptr) {
            // Store the next node after the reversed sublist to be connected later.
            rightNode = temp->next;
            temp->next = nullptr;
        }

        // Reverse the sublist from 'leftNode' to 'rightNode'.
        leftNode = rev(leftNode);

        // Connect the reversed sublist back to the original list.
        if (prev != nullptr) {
            prev->next = leftNode;
        } else {
            head = leftNode;
        }

        // Move 'leftNode' to the end of the reversed sublist.
        while (leftNode->next != nullptr) {
            leftNode = leftNode->next;
        }
        
        // Connect the end of the reversed sublist to the node at position right+1.
        leftNode->next = rightNode;
        
        return head;
    }
};
