#include<iostream>
using namespace std;
int n=0;
int fun(int x){
    static int n=0;
    if(x>0){
        n++;
        return fun(x-1)+n;
    }
    return 0;
}
int main(){
    int r;
    r=fun(5);
    cout<<r;

    r=fun(5);
    cout<<r;
    return 0;
}