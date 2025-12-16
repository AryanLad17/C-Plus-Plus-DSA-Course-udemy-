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
        void reverse(){
            Node* temp=head;
            Node* prev=NULL;
            Node* next=NULL;
            while(temp!=NULL){
                next=temp->next;
                temp->next=prev;
                prev=temp;
                temp=next;
            }
            head=prev;
        }
        void recursive_reverse(Node* temp,Node* prev){
            if(temp!=NULL){
                recursive_reverse(temp->next,temp);
                temp->next=prev;
            }
            else{
                head=prev;
            }
        }
        void recursive_reverse(){
            recursive_reverse(head,NULL);
        }
        Node* reverseRecursive(Node* head){
		    if(head==NULL || head->next==NULL){
			    return head;
		    }
		    Node* newhead=reverseRecursive(head->next);
		    head->next->next=head;
		    head->next=NULL;
		
		    return newhead;
	    }
	    void reverse1() {
    	    head = reverseRecursive(head);
	    }
};
int main(){
    LL l;
    l.create(1);
    l.create(2);
    l.create(3);
    l.create(4);
    l.display();
    cout<<endl;
    
    l.reverse();
    l.display();
    cout<<endl;

    l.recursive_reverse();
    l.display();
    cout<<endl;

    l.reverse1();
    l.display();
    cout<<endl;
    return 0;
}