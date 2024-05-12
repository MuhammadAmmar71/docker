#include <iostream>
using namespace std;
class node
{
    int data;
    node *next;

public:
    node(int data)
    {
        this->data = data;
        next = NULL;
    }

    // INSERT AT TAIL

    void insertAtTail(node *&head, int data)
    {
        node *n = new node(data);
        if (head == NULL)
        {
            insertAtHead(head, data);
            return;
        }
        node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = n;

        n->next = head;
    }
    // INSERT AT HEAD

    void insertAtHead(node *&head, int data)
    {
        node *n = new node(data);
        node *temp = head;
        if (head == NULL)
        {
            n->next = n;
            head = n;
            return;
        }
        else
        {
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = n;
            n->next = head;
            head = n;
        }
    }

    void display(node *head)
    {
        node *temp = head;
        do
        {
            cout << temp->data<<' ';
            temp = temp->next;
        } while (temp != head); // we cannot do temp->next!=head bcoz it will misses the last node
        cout<<endl;
    }

    //  Deletion in a linked list

    void deletion(node *&head, int pos)
    {
        
     if(pos==1){
        deleteAtHead(head);
        return;
     }


        //
        node *temp = head;
        int count=1;
        while (pos-1>count )
        {
            temp = temp->next;
            count++;
        }
        node *todelete = temp->next;
        temp->next = temp->next->next;
        delete todelete;
    }
    // corner case of deletion at head
    void deleteAtHead(node *&head)
    {       
        node* temp=head;
        while(temp->next!=head){
            temp=temp->next;

        }

        node* todelete=head;

        head=head->next;
        temp->next=head;
        delete todelete;
    }
};
int main()
{
    node *head = NULL;
    node n(0);
    n.insertAtTail(head, 1);
    n.insertAtTail(head, 2);
    n.insertAtTail(head, 3);
    n.display(head);
    n.insertAtHead(head, 4);
    n.display(head);
    n.deletion(head,3);
    n.display(head);
    n.deletion(head,1);
    n.display(head);
    
    return 0;
}