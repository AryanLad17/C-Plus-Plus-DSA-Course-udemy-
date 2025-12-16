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
    void levelorder(Node* p){
        queue<Node*> q;
        cout<<p->data<<" ";
        q.push(p);
        while(!q.empty()){
            p=q.front();
            q.pop();
            if(p->lchild!=NULL){
                cout<<p->data<<" ";
                q.push(p->lchild);
            }
            if(p->rchild!=NULL){
                cout<<p->data<<" ";
                q.push(p->rchild);
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
    void levelorder() {
        levelorder(root);
    }

};
int main()
{
    Tree t;
    t.create();
    return 0;
}