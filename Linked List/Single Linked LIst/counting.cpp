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
        void count(){
            Node* temp=head;
            int count=0;
            while(temp!=NULL){
                count++;
                temp=temp->next;
            }
            cout<<count;
        }
        int recusive_count(Node* nn){
            if(nn == NULL)
                return 0;
                return 1 + recusive_count(nn->next);
            }
        void recusive_count(){
            cout<<recusive_count(head);
        }
};
int main(){
    LL l;
    l.create(1);
    l.create(2);
    l.create(3);
    l.create(4);
    l.display();
    cout << endl;
    l.recusive_count();      // this is correct
    return 0;
}
