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
        void duplicated(){
            Node* temp=head;
            Node* next=head->next;
            if (head == NULL || head->next == NULL)   // ✔ fix
            return;
            while(next!=NULL){
                if(next->data!=temp->data){
                    temp=next;
                    next=next->next;
                }
                else{
                    temp->next=next->next;
                    delete next;
                    next=temp->next;
                }
            }
        }
};
int main(){
    LL l;
    l.create(1);
    l.create(1);
    l.create(3);
    l.create(1);
    l.display();
    l.duplicated();
    cout<<endl;
    l.display();
    return 0;
}