#include<iostream>
using namespace std;
class DEQUEUE{
    private:
        int left;
        int right;
        int a[5];
    public:
        DEQUEUE():left(-1),right(-1) {}
        bool isEmpty(){
			return (left==-1) ;
		}
		bool isFull(){
            return (left != -1 && left==(right+1)%5);
        }
        void enqueue_at_left(int x){
            if(isFull()){
                cout<<"Queue is Full";
                return;
            }
            if(left==-1)
                right=left=0;
            else if(left==0)
                left=4;
            else
                left=left-1;
            a[left]=x;
        }
        void enqueue_at_right(int x){
            if(isFull()){
                cout<<"Queue is Full";
                return;
            }
            if(right==-1)
                right=left=0;
            else
                right=(right+1)%5;
            a[right]=x;
        }
        int dequeue_at_left(){
            if(isEmpty()){
                cout<<"Queue is Empty";
                return 0;
            }
            int x=a[left];
            if(left==right)
                left=right=-1;
            else
                left=(left+1)%5;
            
            return x;
        }
        int dequeue_at_right(){
            if(isEmpty()){
                cout<<"Queue is Empty";
                return 0;
            }
            int x=a[right];
            if(left==right)
                left=right=-1;
            else
                right = (right + 1) % 5;  
            
            return x;
        }
};
int main(){
    DEQUEUE d;
    d.enqueue_at_left(1);
    cout<<d.dequeue_at_right();
    d.enqueue_at_right(1);
    cout<<d.dequeue_at_left();
    return 0;
}