/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
private:
 void insertattail( Node * &head ,Node* &tail , int data){
     Node * newNode = new Node(data);
     if( head == NULL ){
         head = newNode;
         tail = newNode;
         return;
     }
     else{
     tail-> next = newNode;
     tail = newNode;}
 }
public:
    Node* copyRandomList(Node* head) {
        
        Node * clonehead = NULL ;
        Node * clonetail = NULL ;
        
        Node * original = head;
        while ( original != NULL ){
            insertattail( clonehead , clonetail , original-> val);
            original = original -> next;
        }
        unordered_map< Node* , Node*> oldtonew ;
        original = head ;
        Node * temp2 = clonehead;
        while ( original != NULL && temp2 != NULL ){
            oldtonew[original] = temp2;
            original = original -> next;
            temp2 = temp2 -> next;
        }
        original = head ;
        temp2 = clonehead;
        while (original != NULL && temp2 != NULL){
            temp2 -> random = oldtonew[original -> random];
            temp2 = temp2 -> next;
            original  = original -> next ;
        }
        return clonehead;
        
    }
};