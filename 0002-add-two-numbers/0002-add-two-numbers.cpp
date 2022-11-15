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
    
    void insertattail( ListNode * &head , ListNode* &tail , int val)
    {
        ListNode *temp = new ListNode(val);
        if ( head == NULL )
        {
            head = temp;
            tail = temp;
            return;
        }
        else {
            tail-> next = temp;
            tail = temp;
        }
    }
    
    ListNode* addition( ListNode* f1 , ListNode* f2)
    {
        int carry = 0;
        int digit = 0;
        int sum = 0;
        
        ListNode * anshead = NULL ;
        ListNode * anstail = NULL ;
        
        while (f1 != NULL ||  f2 != NULL || carry != 0){
        int val1 = 0 ;
        if( f1 != NULL ){
        val1 = f1-> val; 
        }
            
        int val2 = 0 ;
        if( f2 != NULL ){
        val2 = f2 -> val ;
        }
            
        sum = carry + val1 + val2;
        digit = sum % 10;
        insertattail(anshead , anstail , digit );
        carry = sum / 10;
            
        if ( f1 != NULL ){
            f1= f1-> next;
        }
        
        if ( f2 != NULL ){
            f2= f2-> next;     
            
        }
    }
      
    return anshead;
}
    
    ListNode* reverse(ListNode * head)
    {
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode * fwd = NULL ;                                      
        while ( cur != NULL)
        {
            fwd = cur -> next ;
            cur -> next = prev ;
            prev = cur ;
            cur = fwd ;
        
        }
    
    return prev;
    
    } 
   ListNode* addTwoNumbers(ListNode* l1 , ListNode* l2){
        // code here
        // l1  = reverse(l1);
        // l2 = reverse(l2);
       
        ListNode * ans = addition( l1 , l2 );
        
        // ans = reverse( ans );
        
        return ans;
    }
    
    
    
};