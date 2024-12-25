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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* prev = head;

        // Traverse until the next node is null
        while (prev->next != nullptr) {
            ListNode* curr = prev->next; 
            
            int gcdValue = min(prev->val, curr->val);

            // Calculate the GCD
            while (prev->val % gcdValue != 0 || curr->val % gcdValue != 0) {
                gcdValue--;
            }

            // Insert new node with the GCD (greatest common divisor) value between prev and curr
            ListNode* gcdNode = new ListNode(gcdValue); 
            gcdNode->next = curr;                      
            prev->next = gcdNode;                      

            // Move the pointer two steps forward (skip the inserted node)
            prev = curr;
        }

        return head; 
    }
};