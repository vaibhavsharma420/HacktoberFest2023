#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class Queue
{
    Node *head;
    Node *tail;
    int size, cap;

public:
    Queue(int n)
    {
        this->cap = n;
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }
    void enq(int data)
    {
        if (this->size == this->cap)
        {
            cout << "OVERFLOW\n";
            return;
        }
        Node *new_node = new Node(data);
        if (this->head == NULL)
            this->head = this->tail = new_node;
        else
        {
            this->tail->next = new_node;
            this->tail = new_node;
        }
        this->size++;
    }
    void deq()
    {
        if (this->head == NULL)
        {
            cout << "UNDERFLOW\n";
            return;
        }

        else
        {
            Node *oldh = this->head;
            Node *newh = this->head->next;
            this->head = newh;
            if (this->head == NULL)
                this->tail == NULL;
            cout << "Element deleted:" << oldh->data << endl;
            oldh->next = NULL;
            delete oldh;
            this->size--;
        }
    }
    bool isemp()
    {
        return this->head == NULL;
    }
    int getele()
    {
        if (this->head == NULL)
        {
            cout << "UNDERFLOW\n";
            return -1;
        }
        cout << "Size:" << this->size << endl;
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << '\t';
            temp = temp->next;
        }
        cout << endl;
        return 0;
    }
};
int main()
{
    int n, ch = 0, ele;
    Queue q(10);
    cout << "Menu\n1 for insertion\n2 for deletion\n3 for display\n4 to check if the queue is empty\nother for exit\n";

    while (1)
    {
        cout << "Enter your choice\n";
        cin >> ch;

        if (ch == 1)
        {
            cout << "Enter the element you want to insert\n";
            cin >> ele;
            q.enq(ele);
        }
        else if (ch == 2)
        {
            q.deq();
        }
        else if (ch == 3)
        {
            q.getele();
        }
        else if (ch == 4)
        {
            if (q.isemp())
                cout << "Queue is empty\n";
            else
                cout << "Queue is not empty\n";
        }

        else
            break;
    }

    return 0;
}