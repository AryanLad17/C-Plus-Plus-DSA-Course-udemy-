#include<iostream>
using namespace std;
struct test{
    int a[5];
    int n;
};
void fun(struct test t){
    t.a[0]=7;
    cout<<t.a[0]<<endl;
}
int main(){
    struct test t={{2,4,6,3,5},9};
    fun(t);
    for(int i=0;i<5;i++)
    cout<<t.a[i]<<" ";
    return 0;
}