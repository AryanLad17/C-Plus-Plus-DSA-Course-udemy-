#include<iostream>
#include<stdio.h>
using namespace std;
struct rect{
    int len;
    int bred;
};
int main(){
    struct rect r={10,5};
    struct rect *p=&r;
    p=(struct rect *)malloc(sizeof(struct rect));
    p->len=13;
    cout<<p->len;
    return 0;
}