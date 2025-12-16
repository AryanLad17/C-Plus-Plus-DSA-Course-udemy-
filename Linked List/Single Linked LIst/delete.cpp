#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
class LL
{
    Node *head;

public:
    LL() : head(NULL) {}
    void create(int x)
    {
        Node *nn = new Node;
        nn->data = x;
        nn->next = NULL;
        if (head == NULL)
            head = nn;
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = nn;
        }
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void todelete(int key)
    {
        Node *temp = head;
        Node *q = NULL;
        if (head == NULL)
        {
            cout << "Not found" << endl;
            return;
        }
        while (temp != NULL && temp->data != key)
        {
            q = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Not found" << endl;
            return;
        }
        if (q == NULL)
            head = head->next;
        else
            q->next = temp->next;
        delete temp;
    }

    void index_todelete(int index)
    {
        Node *temp = head;
        if (index == 0)
        {
            head = head->next;
            delete temp;
            return;
        }
        for (int i = 1; i < index && temp != NULL; i++)
        {
            temp = temp->next;
        }
        Node *todelete = temp->next;
        temp->next = todelete->next;
        delete todelete;
    }
    
};
int main()
{
    LL l;
    l.create(1);
    l.create(2);
    l.create(3);
    l.create(4);
    l.display();
    cout << endl;
    l.todelete(0);
    // l.index_todelete(0);
    l.display();
    return 0;
}