#include<iostream>
#include<queue>
using namespace std;
struct Node{
    int data;
    Node* lchild;
    Node* rchild;
};
class Count{
    Node* root;
    int count(Node *p)
    {       
        if(p!=NULL)
            return count(p->lchild)+count(p->rchild)+1;
    
        return 0;
    }
    int count_deg_2(Node *p)
    {    
        int x; 
        int y; 
        if(p!=NULL){
             x=count_deg_2(p->lchild);
             y=count_deg_2(p->rchild);
            if(p->lchild!=NULL && p->rchild!=NULL)
                return x+y+1;
            else
                return x+y;
        }
    
        return 0;
    }
    int sum(Node *p)
    {  
        int x,y;     
        if(p!=NULL){
            x= sum(p->lchild);
            y= sum(p->rchild);
            return x+y+p->data;
        }
        return 0;
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
    int leaf(Node *p)
    {  
        int x,y;     
        if(p!=NULL){
            x= leaf(p->lchild);
            y= leaf(p->rchild);
            if(p->lchild==NULL && p->rchild==NULL)
                return x+y+1;
            else 
                return x+y;
        }
        return 0;
    }
    public:
        Count():root(NULL){}
        void create(){
            int x;
            queue<Node*> q;
            Node* p;
            Node* t;
            cout<<"Enter the root node:";
            cin>>x;
            if (x == -1)
            {
                root = NULL;
                return; // no tree
            }
            root=new Node{x,NULL,NULL};
            q.push(root);
            while(!q.empty()){
                p=q.front();
                q.pop();
                cout<<"Enter the Left child:";
                cin>>x;
                if(x!=-1){
                    t=new Node{x,NULL,NULL};
                    p->lchild=t;
                    q.push(t);
                }
                cout<<"Enter the right child:";
                cin>>x;
                if(x!=-1){
                    t=new Node{x,NULL,NULL};
                    p->rchild=t;
                    q.push(t);
                }
            }
        }
        
        void count(){
            cout <<count(root);
        }
        void count_deg_2(){
            cout <<count_deg_2(root);
        }
        void sum(){
            cout <<sum(root);
        }
        void height(){
            cout <<height(root);
        }
        void leaf(){
            cout <<leaf(root);
        }
};
int main(){
    Count c;
    c.create();
    c.count();
    cout<<endl;
    c.count_deg_2();
    cout<<endl;
    c.sum();
    cout<<endl;
    c.leaf();
    cout<<endl;
    c.height();
    return 0;
}
