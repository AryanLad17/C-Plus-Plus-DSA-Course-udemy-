#include<iostream>
using namespace std;
int * fun(int n){
    int *p;
    p=new int[n];
    for(int i=0;i<n;i++)
        p[i]=i+1;
    return p;
}
int main(){
    int *ptr,sz=5;
    ptr=fun(sz);
    for(int i=0;i<sz;i++)
        cout<<ptr[i]<<" ";
    delete[] ptr;

    return 0;
}