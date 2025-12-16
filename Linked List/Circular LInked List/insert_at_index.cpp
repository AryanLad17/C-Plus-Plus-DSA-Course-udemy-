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
        void insert_at_index(int key,int index){
            Node* temp=head;
            Node* nn=new Node;
            nn->next=NULL;
            nn->data=key;
                if(index == 0){
                    if(head == NULL){
                        head = nn;
                        nn->next = head;
                        return;
                    }

                    Node* temp = head;
                    while(temp->next != head)
                        temp = temp->next;
                    temp->next = nn;
                    nn->next = head;
                    head = nn;
                    return;
                }
            for(int i=0;i<index-1 && temp->next!=head;i++)
                temp=temp->next;
            nn->next=temp->next;
            temp->next=nn;
        }
};
int main(){
    CLL c;
    c.insert(1);
    c.insert(2);
    c.insert(3);
    c.insert(4);
    c.display();
    c.insert_at_index(4,2);
    c.display();
    return 0;
}