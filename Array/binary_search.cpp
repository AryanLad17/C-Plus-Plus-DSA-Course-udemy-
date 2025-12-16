#include<iostream>
using namespace std;
void binary(int a[],int low,int high,int key){
    
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==key){
            cout<<"Elemet found at index:"<<mid<<endl;
            return;
        }
        else if(a[mid]<key)
            low=mid+1;
        else
            high=mid-1;
    }
}
void recursive_binary(int a[],int low,int high,int key){
    
    if(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==key){
            cout<<"Elemet found at index:"<<mid<<endl;
            return;
        }
        else if(a[mid]<key)
            recursive_binary(a,mid+1,high,key);
        else
            recursive_binary(a,low,mid-1,key);
    }
}
int main(){
    int a[6] = {2,3,5,6,7,9};   // ✔ Sorted

    binary(a,0,5,6);
    recursive_binary(a,0,5,6);
    return 0;
}
