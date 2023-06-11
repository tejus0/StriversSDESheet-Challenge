/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/

Node *firstNode(Node *head)
{
    //    Write your code here.
    if(!head || !head->next)
            return NULL;
        Node * turtle=head;
        Node * rabbit=head;
        //ListNode * ;
        while(rabbit->next and rabbit->next->next){
            rabbit=rabbit->next->next;
            turtle= turtle->next;
            if(rabbit==turtle){
                turtle=head;
                while(rabbit!=turtle){
                    rabbit=rabbit->next;
                    turtle=turtle->next;
                }
                return rabbit;
            }
        }
        return NULL;
}