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
    ListNode* mergeNodes(ListNode* head) {
        // initial case
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // Initialize pointers for traversal
        ListNode* temp1 = head;        
        ListNode* temp2 = head->next; 
        long long sum = 0;           
        
        // Traverse the list until the end
        while (temp2 != nullptr) {
            
            if (temp2->val == 0) {
                // Create a new node with the computed sum
                ListNode* newNode = new ListNode(sum);
                temp1->next = newNode;
                newNode->next = temp2->next;
                temp1 = newNode;
                // Reset 
                sum = 0;
            } else {
                
                sum += temp2->val;
            }
            
            // Move to the next node
            temp2 = temp2->next;
        }
        
        //skipping the initial dummy node
        return head->next;
    }
};
