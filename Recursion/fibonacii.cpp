#include<iostream>
using namespace std;
int fib(int n){                     //using loop
    int t0=0,t1=1,s;
    for(int i=2;i<=n;i++){
        s=t0+t1;
        t0=t1;
        t1=s;
    }
    return s;
}
int fib1(int n){                  //using recursion
    if(n<=1)
        return n;
    return fib1(n-2)+fib1(n-1);
}
int fib2(int n){                 //using memoization 
    int f[10];
    for(int i=0;i<n;i++)
        f[i]=-1;
    if(n<=1){
        f[n]=n;
        return n;
    }
    else{
        if(f[n-2]==1)
            f[n-2]=fib2(n-2);
        if(f[n-1]==-1)
            f[n-1]=fib2(n-1);
        return fib2(n-2)+fib2(n-1);
    }
}
int main(){
    cout<<fib(5)<<endl;
    cout<<fib1(5)<<endl;
    cout<<fib2(5)<<endl;
    return 0;
}