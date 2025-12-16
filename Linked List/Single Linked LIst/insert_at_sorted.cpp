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
        void insert(int key){
            Node* temp=head;
            Node* prev=NULL;
            Node* nn=new Node;
            nn->next=NULL;
            nn->data=key;
            if(head == NULL){
                head = nn;
                return;
            }
            if(temp->data>key){
                nn->next=head;
                head=nn;
                return;
            }
            while(temp!=NULL && temp->data<key){
                prev=temp;
                temp=temp->next;
            }
            
            nn->next=prev->next;
            prev->next=nn;
        }
};
int main(){
    LL l;
    l.create(2);
    l.create(3);
    l.create(4);
    l.create(5);
    l.display();
    cout<<endl;
    l.insert(6);
    l.display();
    return 0;
}