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
        bool check(){
            Node* temp=head;
            int x=-32768;
            while(temp!=NULL){
                if(temp->data<x){
                    cout<<"List is not sorted"<<endl;
                    return false;
                }
                x=temp->data;
                temp=temp->next;
            }
            cout<<"List is sorted"<<endl;
            return true;
        }
};
int main(){
    LL l;
    l.create(1);
    l.create(2);
    l.create(1);
    l.create(4);
    l.display();
    l.check();
    return 0;
}
