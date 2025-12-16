#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
class Queue{
    private:
        Node* front;
        Node* rear;
    public:
        Queue():front(NULL),rear(NULL){}
        bool isEmpty(){
            return (front==NULL);
        }
        void enqueue(int x){
            Node* nn=new Node;
            nn->next=NULL;
            nn->data=x;
            if(front==NULL)
                front=rear=nn;
            else{
                rear->next=nn;
                rear=nn;
            }
        }
        void dequeue(){
            cout<<front->data<<" ";
            Node* temp=front;
            front=front->next;
            if(front==NULL)
                rear=NULL;
            delete temp;
        }
        void display(){
            Node* temp=front;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
};
int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.dequeue();
    cout<<endl;
    q.display();
    return 0;
}