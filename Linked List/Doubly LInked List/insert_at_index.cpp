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
        void insert_at_index(int key,int index){
            Node* nn=new Node;
            nn->data=key;
            nn->next=nullptr;
            nn->prev=nullptr;
            if(index == 0){
                nn->next = head;
                if(head != nullptr)
                    head->prev = nn;
                head = nn;
                return;
            }
            Node* temp=head;
            for(int i=0;i<index-1 && temp!=NULL;i++)
                temp=temp->next;
            nn->next=temp->next;
            if(temp->next) temp->next->prev=nn;
            temp->next=nn;
            nn->prev=temp;
        }
        void delete_at_index(int index){
            if(index==0){
                Node* next=head;
                head=head->next;
                if(head != NULL){
                    head->prev = NULL;
                }
                delete next;
                return;
            }
            Node* temp=head;
				for(int i=0;i< index-1 && temp!=NULL;i++){
					temp=temp->next;
				}
                if(temp == NULL || temp->next == NULL)
                    return;
					Node* tonext=temp->next;
					temp->next=tonext->next;
                    if(temp->next != NULL)
					    temp->next->prev=temp;
				delete tonext;
        }
};
int main(){
    DLL d;
    d.create(5);
    d.create(7);
    d.create(9);
    d.create(8);
    // d.insert_at_index(2,0);
    d.delete_at_index(0);
    d.display();
    return 0;
}