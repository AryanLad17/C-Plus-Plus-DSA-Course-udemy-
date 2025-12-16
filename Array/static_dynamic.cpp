#include<iostream>
using namespace std;
int main(){
    int a[5];
    int *p;
    p=new int[5];
    p[0]=1;
    a[0]=1;
    cout<<p[0];
    cout<<a[0];
    cout<<&a[0]<<endl;
    cout<<&p[0]<<endl;
    return 0;
}