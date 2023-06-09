// 1st Approach - O ( N) + O (N) time
Node* removeKthNode(Node* head, int n)
{
    // Write your code here.
    Node *temp = head;
        int count = 0;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        temp = head;
        for(int i=1;i<count-n;i++){
            temp = temp->next;
        }
        if(count-n==0){
            return head->next;
        }
        if(temp->next!=NULL){
            temp->next = temp->next->next;
            return head;
        }else{
            return NULL;
        }
}

// 2nd Approach - O(N) Time

Node *slow=head, *fast=head;
    while(n--){
        fast=fast->next;
    }
    if(!fast)   return slow->next;
    while(fast->next){
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=slow->next->next;
    return head;


