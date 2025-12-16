#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
class CLL
{
    Node *head;

public:
    CLL() : head(NULL) {}
    void insert(int key)
    {
        Node *nn = new Node;
        nn->next = NULL;
        nn->data = key;
        if (head == NULL)
        {
            head = nn;
            nn->next = head;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = nn;
            nn->next = head;
        }
    }
    void display()
    {
        Node *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
    void delete_key(int key)
    {
        // Case 1: Empty list
        if (head == NULL)
        {
            cout << "Not found\n";
            return;
        }

        Node *temp = head;

        // Case 2: Head is the node to delete
        if (head->data == key)
        {
            Node *last = head;

            // Find last node
            while (last->next != head)
                last = last->next;

            // If only one node
            if (head->next == head)
            {
                delete head;
                head = NULL;
                return;
            }

            // More than one node
            last->next = head->next;
            Node *del = head;
            head = head->next;
            delete del;
            return;
        }

        // Case 3: Deleting a non-head node
        while (temp->next != head && temp->next->data != key)
        {
            temp = temp->next;
        }

        // Key not found
        if (temp->next == head)
        {
            cout << "Not found\n";
            return;
        }

        // Delete node
        Node *del = temp->next;
        temp->next = del->next;
        delete del;
    }
    void delete_at_index(int index)
    {
        if (head == NULL)
            return; // empty list

        Node *temp = head;

        // -------------------------
        // Case 1: delete head (index = 0)
        // -------------------------
        if (index == 0)
        {
            // single node case
            if (head->next == head)
            {
                delete head;
                head = NULL;
                return;
            }

            // find last node (because we don't have tail)
            Node *last = head;
            while (last->next != head)
                last = last->next;

            // delete head
            last->next = head->next;
            Node *del = head;
            head = head->next;
            delete del;
            return;
        }

        // -------------------------
        // Case 2: delete non-head
        // -------------------------

        Node *prev = NULL;

        for (int i = 0; i < index; i++)
        {
            prev = temp;
            temp = temp->next;

            // if we loop back to head → index too large
            if (temp == head)
                return;
        }

        // delete node at index
        prev->next = temp->next;
        delete temp;
    }
};
int main()
{
    CLL c;
    c.insert(1);
    c.insert(2);
    c.insert(3);
    c.insert(4);

    c.delete_key(3);
    c.display();
    return 0;
}