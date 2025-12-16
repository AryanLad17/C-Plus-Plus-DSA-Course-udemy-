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
    void perorder(Node *p)
    {
        if (p)
        {
            cout << p->data << " ";
            perorder(p->lchild);
            perorder(p->rchild);
        }
    }
    int height(Node *p)
    {  
        int x,y;     
        if(p!=NULL){
            x= height(p->lchild);
            y= height(p->rchild);
            if(x>y)
                return x+1;
            else
                return y+1;
        }
        return 0;
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

    void preorder()
    {
        if (root == NULL)
        {
            cout << "Tree is empty";
            return;
        }
        perorder(root); // call the private one
    }
    void height(){
            cout <<height(root);
        }

};
int main()
{
    Tree t;
    t.create();
    t.preorder();
    cout<<endl;
    t.height();
    return 0;
}