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
        LL connect(LL l2){
            Node* temp=head;
            Node* second=l2.head;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=second;
            second=NULL;
        }
};
int main(){
    LL l,l2,l3;
    l.create(1);
    l.create(2);
    l.create(3);
    l.create(4);
    l.display();
    cout<<endl;
    l2.create(5);
    l2.create(6);
    l2.create(7);
    l2.create(8);
    l2.display();
    cout<<endl;
    l3=l.connect(l2);
    l3.display();
    cout<<endl;
    l.display();
    return 0;
}