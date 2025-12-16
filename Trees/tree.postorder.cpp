
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
struct Node
{
    int data;
    Node *lchild;
    Node *rchild;
};
class Tree
{
private:
    Node *root;
    void postorder(Node *p)
    {
        if (p)
        {

            postorder(p->lchild);
            postorder(p->rchild);
            cout << p->data << " ";
        }
    }

    void iterative_postorder(Node *root)
    {
        if (root == NULL)
            return;

        stack<Node *> st;
        Node *current = root;
        Node *lastVisited = NULL;

        while (!st.empty() || current != NULL)
        {

            if (current != NULL)
            {
                st.push(current);
                current = current->lchild;
            }
            else
            {
                Node *topNode = st.top();

                // If right child exists and not visited, go right
                if (topNode->rchild != NULL && lastVisited != topNode->rchild)
                {
                    current = topNode->rchild;
                }
                else
                {
                    cout << topNode->data << " ";
                    lastVisited = topNode;
                    st.pop();
                }
            }
        }
    }

public:
    Tree() : root(NULL) {}
    void create()
    {
        Node *p;
        Node *t;

        int x;
        queue<Node *> q;
        cout << "ENter the root node:";
        cin >> x;
        if (x == -1)
        {
            root = NULL;
            return; // no tree
        }
        root = new Node{x, NULL, NULL};
        q.push(root);
        while (!q.empty())
        {
            p = q.front();
            q.pop();
            cout << "Enter the left child:";
            cin >> x;
            if (x != -1)
            {
                t = new Node{x, NULL, NULL};
                p->lchild = t;
                q.push(t);
            }
            else
                p->lchild = NULL;
            cout << "Enter the right child:";
            cin >> x;
            if (x != -1)
            {
                t = new Node{x, NULL, NULL};
                p->rchild = t;
                q.push(t);
            }
            else
                p->rchild = NULL;
        }
    }

    void postorder()
    {
        if (root == NULL)
        {
            cout << "Tree is empty";
            return;
        }
        postorder(root); // call the private one
    }
    void iterative_postorder() {
        iterative_postorder(root);
    }

};
int main()
{
    Tree t;
    t.create();
    t.postorder();
    cout << endl;
    t.iterative_postorder();
    return 0;
}