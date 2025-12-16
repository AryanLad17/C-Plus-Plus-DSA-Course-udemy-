#include<iostream>
using namespace std;
class Queue{
    private:
        int front;
        int rear;
        int a[5];
    public:
        Queue(): front(-1),rear(-1){}
        bool isEmpty(){
            return(front==rear);
        }
        bool isFull(){
            return(rear==5-1);
        }
        void enqueue(int x){
            if(isFull()){
                cout<<"Queue is Full";
                return;
            }
            rear++;
            a[rear]=x;
        }
        int dequeue(){
            if(isEmpty()){
                cout<<"Queue is Empty";
                return 0;
            }
            front++;
            int x=a[front];
            
            return x;
        }
};
int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout<<q.dequeue();
    cout<<q.dequeue();
    cout<<q.dequeue();
    cout<<q.dequeue();
    return 0;
}