#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
class LL{
    Node* head;
    public:
        LL(): head(NULL) {}
        void create(int x){
            Node* nn=new Node;
            nn->data=x;
            nn->next=NULL;
            if(head==NULL)
                head=nn;
            else{
                Node* temp=head;
                while(temp->next!=NULL)
                    temp=temp->next;
                temp->next=nn;
            }
        }
        void display(){
            Node* temp=head;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
        }
        void recursive_display(Node *nn){
            if(nn!=NULL){
                recursive_display(nn->next);
                cout<<nn->data<<" ";
                
            }
        }
        void recursive_display(){
            recursive_display(head);
        }

};
int main(){
    LL l;
    l.create(1);
    l.create(2);
    l.create(3);
    l.create(4);
    l.display();
    l.recursive_display();
    return 0;
}