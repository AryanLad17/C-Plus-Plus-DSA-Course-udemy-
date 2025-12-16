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
        void sum(){
            int sum=0;
            Node* temp=head;
            while(temp!=NULL){
                sum+=temp->data;
                temp=temp->next;
            }
            cout<<sum;
        }
        int recusive_sum(Node * nn){
            if(nn==NULL)
                return 0;
            return recusive_sum(nn->next)+nn->data;
        }
        void recusive_sum(){
            cout<<recusive_sum(head);
        }

};
int main(){
    LL l;
    l.create(1);
    l.create(2);
    l.create(3);
    l.create(4);
    l.display();
    l.sum();
    l.recusive_sum();
    return 0;
}