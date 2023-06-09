Node *addTwoNumbers(Node *l1, Node *l2)
{
    // Write your code here.
    Node* dummy=new Node ;
        Node* temp=dummy;
        int carry=0;
        while(l1 or l2 or carry) {
            int sum=0;
            if(l1){
                sum+=l1->data;
                l1=l1->next;
            }
            if(l2){
                sum+=l2->data;
                l2=l2->next;
            }
            sum+=carry;
            Node* node=new Node(sum%10);
            carry=sum/10;
            temp->next=node;
            temp=node;
        }
        return dummy->next;
}