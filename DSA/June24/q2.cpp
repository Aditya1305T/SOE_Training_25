class Solution {
  public:
    /* Function to delete a node from a linked list */
    Node* deleteNode(Node* head, int x) {
        Node dummy(-1);
        dummy.next = head;
        Node* curr = &dummy;
        for(int i = 0; i < x-1; i++){
            curr = curr->next;
        }
        
        curr->next = curr->next->next;
        return dummy.next;
    }
};