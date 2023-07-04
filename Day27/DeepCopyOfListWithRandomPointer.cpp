#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

// Time - O(N)  Space - O(1)

LinkedListNode<int> * cloneRandomList(LinkedListNode<int> * head) {
        if(head==NULL) return NULL;
        LinkedListNode<int>*temp=head;
        while(temp!=NULL){
            LinkedListNode<int>* newNode=new LinkedListNode<int>(temp->data);
            newNode->next=temp->next;
            temp->next=newNode;
            temp=temp->next->next;
        }
        temp=head;
        while(temp!=NULL){
            if(temp->next!=NULL && temp->random!=NULL) temp->next->random=temp->random->next;
            else temp->next->random=NULL;
            temp=temp->next->next;
        }
        temp=head;
        LinkedListNode<int>*Head=temp->next,*newTemp=temp->next;
        while(temp!=NULL){
            if(temp->next!=NULL && newTemp->next!=NULL){
                temp->next=temp->next->next;
                newTemp->next=newTemp->next->next;    
            }
            else{
                temp->next=NULL;
                newTemp->next=NULL;
            }
            temp=temp->next;
            newTemp=newTemp->next;
        }
        return Head;
    }



