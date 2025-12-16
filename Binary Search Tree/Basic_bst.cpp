#include <iostream>
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
    int search(int key)
    {
        Node *t = root;
        if (t == NULL)
            return -1;
        if (key == t->data)
        {
            cout << "Data is found ";
            return 0;
        }
        else if (key > t->data)
            t = t->rchild;
        else
            t = t->rchild;
        cout << "data not found";
    }
    Node* recursiv_insert(Node* t,int key){
        Node* p;
        if(t==NULL){
            p = new Node{key, NULL, NULL};
            return p;
        }
         if (key > t->data)
            t->rchild=recursiv_insert(t->rchild,key);
        else if(key<t->data)
            t->lchild=recursiv_insert(t->lchild,key);
        return t;
        
    }
    void recursiv_insert(int key){
        root =recursiv_insert(root,key);
    }
    void inorder()
    {
        inorder(root);
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
    b.recursiv_insert(80);
    b.inorder();
    b.search(20);
    return 0;
}