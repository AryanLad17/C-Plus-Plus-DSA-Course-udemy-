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
        void search(int x){
            Node* temp=head;
            while(temp!=NULL){
                if(temp->data==x){
                    cout<<"The data is found"<<endl;
                    return;
                }   
                temp=temp->next;
            }
            cout<<"Not found";
        }
        void move_to_head_search(int key){
            Node* temp=head;
            Node* prev=NULL;
            while(temp!=NULL){
                if(temp->data==key){
                    prev->next=temp->next;
                    temp->next=head;
                    head=temp;
                    cout<<"Found";
                    return;
                }
                prev=temp;
                temp=temp->next;
            }
            cout<<"Not found";
        }
};
int main(){
    LL l;
    l.create(1);
    l.create(2);
    l.create(3);
    l.create(4);
    l.display();
    l.search(3);
    l.move_to_head_search(6);
    return 0;
}