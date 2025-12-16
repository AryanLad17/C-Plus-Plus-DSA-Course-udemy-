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
					Node* tonext=head;
					temp->next=tonext->next;
                    if(temp->next != NULL)
					    temp->next->prev=temp;
				delete tonext;
        }
        void todelete(int key){
            if(head==NULL) return;
            Node* temp=head;
            while(temp!=NULL){
                if(temp->data==key){
                    if(temp==head){
                        head=head->next;
                        if(head != NULL){
                            head->prev = NULL;
                        }
                    }
                    else{
                        temp->prev->next=temp->next;
                        if(temp->next!=NULL)
                            temp->next->prev=temp->prev;
                    }
                    delete temp;
                    return;
                }
                temp=temp->next;
            }
        }
};
int main(){
    DLL d;
    d.create(5);
    d.create(7);
    d.create(9);
    d.create(8);
    // d.delete_at_index(0);
    d.todelete(5);
    d.display();
    return 0;
}