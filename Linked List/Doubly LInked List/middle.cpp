#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
};
class DLL{
    Node* head;
    public:
        DLL():head(NULL) {}
        void create(int key){
            Node* nn=new Node;
            nn->data=key;
            nn->next=nullptr;
            nn->prev=nullptr;
            if(head==NULL){
                head=nn;
            }
            else{
                Node* temp=head;
                while(temp->next!=NULL)
                    temp=temp->next;
                temp->next=nn;
                nn->prev=temp;
            }
        }
        void display(){
            Node* temp=head;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
        }
        void mid(){
            Node* fast=head;
            Node* slow=head;
            while( fast->next!=NULL && fast->next->next!=NULL){
                fast=fast->next->next;
                slow=slow->next;
            }
            cout<<slow->data;
        }
};
int main(){
    DLL d;
    d.create(1);
    d.create(2);
    d.create(3);
    d.create(4);
    d.create(5);
    d.display();
    cout<<endl;
    d.mid();
    return 0;
}