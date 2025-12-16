#include<iostream>
using namespace std;
int fun(int n){
    if(n==0)
        return 0;
    else 
        return fun(n-1)+n;
}
int sum(int n){
    return n*(n+1)/2;
}
int sum1(int n){
    int s=0;
    for(int i=1;i<=n;i++)
        s+=i;
    return s;
}
int main(){
    cout<<fun(5);
    cout<<sum(5);
    cout<<sum1(5);
    return 0;
}