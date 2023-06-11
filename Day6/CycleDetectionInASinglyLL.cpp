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

bool detectCycle(Node *list)
{
	//	Write your code here
         Node *slow_p = list, *fast_p = list;

	// Iterate and find if loop exists or not
	while (slow_p && fast_p && fast_p->next) {
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;

		/* If slow_p and fast_p meet at some point then there
		is a loop */
		if (slow_p == fast_p) {
			//removeLoop(slow_p, list);

			/* Return 1 to indicate that loop is found */
			return 1;
		}
	}

	/* Return 0 to indicate that there is no loop*/
	return 0;
}