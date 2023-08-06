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

class Solution
{
    public:
    void insertAtTail(Node* &head, Node* &tail, int d){
        Node* newNode = new Node(d);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    Node *copyRandomList(Node *head)
    {
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;
        
        // Step 1 - Create a clone LL
        while(temp != NULL){
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }
        
        // Step 2 - Create a map
        unordered_map<Node*, Node*> mp;
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL){
            mp[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        
        // Step 3 - Map random pointers
        originalNode = head;
        cloneNode = cloneHead;
        while(originalNode != temp){
            cloneNode->random = mp[originalNode->random];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        
        return cloneHead;
    }
};