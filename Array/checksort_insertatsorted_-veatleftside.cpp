#include<iostream>
using namespace std;
void insert_at_sorted_array(int a[],int n,int key){
    int i=n-1;
    while(i>=0 &&  a[i]>key){
        a[i+1]=a[i];
        i--;
    }
    a[i+1]=key;
}
bool check(int b[],int n){
    for(int i=0;i<n-1;i++){
        if(b[i]>b[i+1]){
            return false;
        }
    }
    cout<<"sorted"<<endl;
    return true;
}
void negtive_at_leftside(int c[],int n){
    int i=0;
    int j=n-1;
    while(i<j){
        while(c[i]<0)
            i++;
        while(c[j]>=0)
            j--;
        if(i<j)
            swap(c[i],c[j]);
    }
}
int main(){
    int a[8]={1,2,3,4,6,8,10};  
    insert_at_sorted_array(a,7,7);
    for(int i=0;i<7;i++)
        cout<<a[i]<<" ";
    cout<<endl;

    int b[7]={1,2,3,24,6,8,10};
    check(b,7);
    cout<<endl;

    int arr[7]={-1,2,-3,4,-5,8,-10};
    negtive_at_leftside(arr,7);
    for(int i=0;i<7;i++)
        cout<<arr[i]<<" ";

        return 0;
}