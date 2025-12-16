#include<iostream>
#include<stdio.h>
using namespace std;
struct rect{
    int len;
    int bred;
};
int main(){
    struct rect r1={10,13};
    cout<<r1.len;
    int a=10;
    char *i;
    int *p;
    p=&a;
    cout<<*p;
    cout<<sizeof(a);
    cout<<sizeof(i);
    delete p;
    return 0;
}