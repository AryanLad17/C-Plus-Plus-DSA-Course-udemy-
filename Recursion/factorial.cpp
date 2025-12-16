#include<iostream>
using namespace std;
int fact(int n){
    if(n==0)
        return 1;
    else 
        return fact(n-1)*n;
}
int fact1(int n){
    int s=1;
    for(int i=1;i<=n;i++)
        s=s*i;
    return s;
}
int main()
{
    cout<<fact(0);
    cout<<fact1(0);
    return 0;
}