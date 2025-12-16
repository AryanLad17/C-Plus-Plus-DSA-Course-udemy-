#include<iostream>
using namespace std;

void set(int a[][3],int b[],int i,int j){
    if(i==j)
        b[i-1]=a[i-1][j-1];
}
int get(int b[],int i,int j){
    if(i==j)
        return b[i-1];
    else return 0;
}
int main(){
    int a[3][3]={{1,0,0},{0,5,0},{0,0,9}};
    int b[3];
    set(a,b,1,1);
    cout<<get(b,1,1);
    return 0;
}