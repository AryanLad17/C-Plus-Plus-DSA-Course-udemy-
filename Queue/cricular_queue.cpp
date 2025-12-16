#include<iostream>
#define size 5
using namespace std;
class Circular_Queue{
    private:
       int front;
       int rear;
       int a[size];
    public:
        Circular_Queue(): front(-1),rear(-1) {}
        bool isEmpty(){
            return(front==-1);
        }
        bool isFull(){
            return(front==(rear+1)%size);
        }
        void enqueue(int x){
            if(isFull()){
                cout<<"Queue is Full";
                return;
            }
            if(isEmpty())
                front=0;
            rear=(rear+1)%size;
            a[rear]=x;
        }
        int dequeue(){
            if(isEmpty()){
                cout<<"Queue is Empty";
            }
            int x=a[front];
            if(front==rear)
                front=rear=-1;
            else
                front=(front+1)%size;
            return x;
        }
        void display(){
            if(isEmpty()){
                cout<<"Queue is Empty";
                return;
            }
            int i=front;
            while(true){
                cout<<a[i]<<" ";
                if(rear==i)
                    break;
                i=(i+1)%size;
            }
            cout<<endl;
        }
};
int main(){
    Circular_Queue c;
     c.dequeue();
    c.enqueue(1);
    c.enqueue(2);
    c.enqueue(3);
    c.enqueue(4);
    // cout<<c.dequeue();
    c.display();
    return 0;
}