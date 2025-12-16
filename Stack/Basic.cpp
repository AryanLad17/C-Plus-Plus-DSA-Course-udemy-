#include<iostream>
using namespace std;
class Stack{
    private:
        int top;
        int a[5];
    public:
        Stack(){
            top=-1;
        }
        bool isEmpty(){
            return (top==-1);
        }
        bool isFull(){
            return (top==4);
        }
        void push(int x){
            if(isFull()){
                cout<<"Stack is Full";
                return;
            }
            top++;
            a[top]=x;
        }
        int pop(){
            if(isEmpty()){
                cout<<"Stack is Empty";
                return 0;
            }
            int x=a[top];
            top--;
            cout<<x;
            return x;
        }
};
int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.pop();
    return 0;
}