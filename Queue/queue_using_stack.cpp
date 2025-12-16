#include<iostream>
#include<stack>
using namespace std;
class Queue_using_Stack{
    private:
        stack<int> s1;
        stack<int> s2;
    public:
        bool isEmpty(){
            return(s1.empty());
        }
        bool isFull(){
            return false;
        }
        void enqueue(int x){
            if(isFull()){
                cout<<"Queue is full";
                return;
            }
            
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(x);
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
        void dequeue(){
            if(isEmpty()){
                cout<<"Queue is Empty";
                return;
            }
            int x=s1.top();
            s1.pop();
            cout<<x;
        }
};

int main(){
     Queue_using_Stack q;
     q.enqueue(1);
     q.enqueue(2);
     q.enqueue(3);
     q.enqueue(4);
     q.dequeue();
     q.dequeue();
     q.dequeue();
     return 0;
}