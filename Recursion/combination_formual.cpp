#include<iostream>
using namespace std;
int fact(int n){
    if(n==0)
        return 1;
    else 
        return fact(n-1)*n;
}
int nCr(int n,int r){
    if(r==0 || n==r)
        return 1;
    return nCr(n-1,r-1) + nCr(n-1,r);
}
int nCr1(int n,int r){
    int num=fact(n);
    int dem=fact(r)*fact(n-r);
    return num/dem;
}
int nCr2(int n,int r){
    if(r==0 || n==r)
        return 1;
    return nCr2(n-1,r-1)+nCr2(n-1,r);
}
int main(){
    cout<<nCr(4,2)<<endl;
    cout<<nCr1(4,3)<<endl;
    cout<<nCr2(4,3)<<endl;
    return 0;
}