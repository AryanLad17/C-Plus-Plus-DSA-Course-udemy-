#include <iostream>
#include <algorithm>
using namespace std;
struct Node
{
    int data;
    Node *lchild;
    Node *rchild;
};
class BST
{
private:
    Node *root;
    void inorder(Node *t)
    {
        if (t)
        {

            inorder(t->lchild);
            cout << t->data << " ";
            inorder(t->rchild);
        }
    }
    int height(Node *p)
    {
        if (p == NULL)
            return 0;
        if (p)
        {
            int x = height(p->lchild);
            int y = height(p->rchild);
            return max(x, y) + 1;
        }
    }

public:
    BST() : root(NULL) {}
    void insert(int key)
    {
        Node *t = root, *r = NULL;
        if (root == NULL) // FIX
        {
            root = new Node{key, NULL, NULL};
            return;
        }
        while (t != NULL)
        {
            r = t;
            if (key == t->data)
                return;
            else if (key < t->data)
                t = t->lchild;
            else
                t = t->rchild;
        }

        // create node AFTER traversal
        Node *newNode = new Node{key, NULL, NULL};

        if (key < r->data)
            r->lchild = newNode;
        else
            r->rchild = newNode;
    }
    void inorder()
    {
        inorder(root);
    }
    void height()
    {
        cout << height(root);
    }
    Node *Inperc(Node *p)
    {
        while (p && p->rchild != nullptr)
        {
            p = p->rchild;
        }
        return p;
    }

    Node *Insucc(Node *p)
    {
        while (p && p->lchild != nullptr)
        {
            p = p->lchild;
        }
        return p;
    }
    Node *Delete(Node *p, int key)
    {
        struct Node *t = NULL;
        if (p == NULL)
            return nullptr;

        if (p->lchild == NULL && p->rchild == NULL)
        {
            if (p == root)
            {
                root = nullptr;
            }
            delete p;
            return nullptr;
        }

        if (p->data > key)
            p->lchild = Delete(p->lchild, key);
        else if (p->data < key)
            p->rchild = Delete(p->rchild, key);
        else
        {
            if (height(p->lchild) > height(p->rchild))
            {
                t = Inperc(p->lchild);
                p->data = t->data;
                p->lchild = Delete(p->lchild, t->data);
            }
            else
            {
                t = Insucc(p->rchild);
                p->data = t->data;
                p->rchild = Delete(p->rchild, t->data);
            }
        }
        return p;
    }
    void Delete(int key)
    {
        root = Delete(root, key);
    }
};
int main()
{
    BST b;
    b.insert(2);
    b.insert(1);
    b.insert(12);
    b.insert(23);
    b.insert(90);

    b.inorder();cout<<endl;
    b.Delete(2);cout<<endl;
    b.height();cout<<endl;
    b.inorder();cout<<endl;
    return 0;
}