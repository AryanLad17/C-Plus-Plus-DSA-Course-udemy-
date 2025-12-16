#include<iostream>
using namespace std; 
void linear(int a[],int n,int key){                             //using noraml linear search 
    for(int i=0;i<n;i++){
        if(a[i]==key){
            cout<<"Element is found at index:"<<i<<endl;
            return;
        }
    }
    cout<<"Element is not found";                              
}
void linear_transpostion(int a[],int n,int key){                     //using transposition linear search
    for(int i=0;i<n;i++){
        if(a[i]==key){
            cout<<"Element is found at index:"<<i<<endl;
            swap(a[i],a[i-1]);
            return;
        }
    }
    cout<<"Element is not found"; 
}
void linear_move_to_head(int a[],int n,int key){                     //using moving to  head  linear search
    for(int i=0;i<n;i++){
        if(a[i]==key){
            cout<<"Element is found at index:"<<i<<endl;
            swap(a[i],a[0]);
            return;
        }
    }
    cout<<"Element is not found"; 
}
int main(){
    int a[5]={2,5,3,7,9};
    linear(a,5,7);
    linear_transpostion(a,5,7);
    linear_move_to_head(a,5,7);
    return 0;
}