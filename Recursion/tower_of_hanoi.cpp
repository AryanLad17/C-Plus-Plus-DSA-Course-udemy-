#include<iostream>
using namespace std;
void toh(int n,int a,int b,int c){
    if(n>0){
        toh(n-1,a,c,b);
        cout<<"from"<<a<<"to"<<c<<endl;
        toh(n-1,b,a,c);
    }
}
void TOH(int n,int A,int B,int C,int D)//for four towes
{
    if(n>0)
    {
    TOH(n-1,A,B,D,C);
    std::cout<<"("<<A<<","<<D<<")"<<std::endl;
    TOH(n-1,C,A,B,D); 
    }
}
int main(){
    toh(3,1,2,3);
    TOH(4,1,2,3,4);

    return 0;
}