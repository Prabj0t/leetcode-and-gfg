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
//  SOLUTION WITH T.C = O(N)  AND   S.C = (1)


class Solution
{
private:
    void insertattail(Node *&head, Node *&tail, int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

public:
    Node *copyRandomList(Node *head)
    {

        Node *clonehead = NULL;
        Node *clonetail = NULL;

        Node *original = head;
        while (original != NULL)
        {
            insertattail(clonehead, clonetail, original->val);
            original = original->next;
        }
        // unordered_map< Node* , Node*> oldtonew ;
        original = head;
        Node *temp2 = clonehead;
        Node *fwd = original;
        Node *fwd2 = temp2;
        while (original != NULL && temp2 != NULL)
        {
            // oldtonew[original] = temp2;
            fwd = original->next;
            original->next = temp2;
            original = fwd;

            fwd2 = temp2->next;
            temp2->next = original;
            temp2 = fwd2;

            // original = original -> next;
            // temp2 = temp2 -> next;
        }
        original = head;
        temp2 = clonehead;
        while (original != NULL && temp2 != NULL)
        {

            if (original->next != NULL)
            {
                if (original->random != NULL)
                {
                    temp2->random = original->random->next;
                }
                else
                {
                    temp2->random = NULL;
                }
            }
            if (original->next != NULL)
            {
                original = original->next->next;
            }
            if (original != NULL)
            {
                temp2 = original->next;
            }
        }
        original = head;
        temp2 = clonehead;
        while (temp2 != NULL && original != NULL)
        {
            original->next = original->next->next;
            original = original->next;

            if (original != NULL)
            {
                temp2->next = original->next;
            }
            temp2 = temp2->next;
        }
        return clonehead;
    }
};