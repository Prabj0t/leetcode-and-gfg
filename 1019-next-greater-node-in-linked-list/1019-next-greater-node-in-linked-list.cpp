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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        ListNode* temp1 = head;
        // ListNode* temp2 = temp1;
        while(temp1 != NULL){   
            ListNode* temp2 = temp1;
            while(temp2 != NULL){
                if(temp1->val < temp2->val){
                    ans.push_back(temp2->val);
                    break;
                    
                }
                else{
                    temp2 = temp2 -> next;
                    if( temp2  == NULL)
                    {
                        ans.push_back(0);
                    }
                }
            }
            
            temp1 = temp1 -> next;
        }   
        return ans;
    }
};