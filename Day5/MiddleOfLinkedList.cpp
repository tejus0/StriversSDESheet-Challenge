Node *findMiddle(Node *head) {
    // Write your code here
    Node* slow=head;
        Node* fast=head;
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
    return slow;
}