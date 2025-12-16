#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
class CLL{
    Node* head;
    public:
        CLL():head(NULL) {}
        void insert(int key){
            Node* nn=new Node;
            nn->next=NULL;
            nn->data=key;
            if(head==NULL){
                head=nn;
                nn->next = head;
            }
            else{
                Node* temp=head;
                while(temp->next != head)
                    temp=temp->next;
                temp->next = nn;
                nn->next = head;
            }
        }
        void display(){
            Node* temp=head;
            do{
                cout<<temp->data<<" ";
                temp=temp->next;
            }while(temp!=head);
            cout<<endl;
        }
};
int main(){
    CLL c;
    c.insert(1);
    c.insert(2);
    c.insert(3);
    c.insert(4);
    c.display();
    return 0;
}