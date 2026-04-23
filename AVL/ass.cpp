#include<iostream>
#include <algorithm>
struct Node{
    int data;
    int height;
    Node* lchild;
    Node* rchild;
};
class AVL{
    private:
        Node* root;
    int height(Node* t){
        if(t==NULL) return -1;
        return t->height;
    }
    int balancefactor(Node* t){
        if(t==NULL) return 0;
        return height(t->lchild)-height(t->rchild);
    }
    void inorder(Node* root){
			Node *t=root;
			if(t){
				
				inorder(t->lchild);
				std::cout<<t->data<<" ";
				inorder(t->rchild);
			}
		}
    Node* rightrotation(Node* parent){
        Node* child=parent->lchild;
        parent->lchild=child->rchild;
        child->rchild=parent;
        parent->height=1+std::max(height(parent->lchild),height(parent->rchild));
        child->height=1+std::max(height(child->lchild),height(child->rchild));
        return child;
    }
    Node* leftrotation(Node* parent){
        Node* child=parent->rchild;
        parent->rchild=child->lchild;
        child->lchild=parent;
        parent->height=1+std::max(height(parent->lchild),height(parent->rchild));
        child->height=1+std::max(height(child->lchild),height(child->rchild));
        return child;
    }
    Node* insert(Node* root,int key){
            if(root==NULL)
                return new Node{key,0,NULL,NULL};
            if(root->data>key)
                root->lchild=insert(root->lchild,key);
            else if(root->data<key)
                root->rchild=insert(root->rchild,key);
            else
                return root;
            root->height=1+std::max(height(root->lchild),height(root->rchild));
            int bf=balancefactor(root);

            //LL
            if(bf>1 && key<root->lchild->data)
                root=rightrotation(root);
            //LR
            if(bf>1 && key>root->lchild->data){
                root->lchild=leftrotation(root->lchild);
                root=rightrotation(root);
            }
            //RR
            if(bf<-1 && key>root->rchild->data)
                root=leftrotation(root);
            //RL
            if(bf<-1 && key<root->rchild->data){
                root->rchild=rightrotation(root->rchild);
                root=leftrotation(root);
            }
            return root;

        }
    Node* Delete(Node* root,int key){
        if(root==NULL) return NULL;
        if(root->data>key)
            root->lchild=Delete(root->lchild,key);
        else if(root->data<key)
            root->rchild=Delete(root->rchild,key);
        else{
            if(root->lchild==NULL || root->rchild==NULL){
                Node* temp=(root->lchild!=NULL) ? root->lchild: root->rchild;
                delete root;
                return temp;
            }
            Node* succ=root->rchild;
            while(succ->lchild!=NULL)
                succ=succ->lchild;
            root->data=succ->data;
            root->rchild=Delete(root->rchild,succ->data);
        }
        root->height = 1 + std::max(height(root->lchild),height(root->rchild));
        int bf=balancefactor(root);

            //LL
            if(bf>1 && balancefactor(root->lchild)>=0)
                return rightrotation(root);
            //RR
            if(bf <-1 && balancefactor(root->rchild)<=0)
                return leftrotation(root);
            //RL
            if(bf <-1 && balancefactor(root->rchild)>0){
                root->rchild=rightrotation(root->rchild);
                return leftrotation(root);
            }
            //LR
            if(bf > 1 && balancefactor(root->lchild)<0){
                root->lchild=leftrotation(root->lchild);
                return rightrotation(root);
            }
            return root;
    }
    public:
        AVL(): root(NULL) {}
        
        void insert(int id){
			root=insert(root,id);
		}
        void inorder(){
			inorder(root);
		}
        void Delete(int key){
            Delete(root,key);
        }
};
int main(){
	AVL a;
	a.insert(2);
	a.insert(1);
	a.insert(4);
	a.insert(3);
    a.Delete(3);
	a.inorder();
    return 0;
}
