#include<iostream>
using namespace std;
void missing(int a[],int n){                    //missing element form first n natural element
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    int s=n*(n+1)/2;
    cout<<sum-s<<endl;
}
void miss1(int a[],int n){                          // missing element from n element 
    int diff=a[0]-0;
    for(int i=0;i<n;i++){
        if(a[i]-i!=diff){
            cout<<i+diff<<endl;
            break;
        }
    }
}
void miss2(int a[],int n){
   int diff=a[0]-0;
    for(int i=0;i<n;i++){
        if(a[i]-i!=diff){
            while(diff<a[i]-i){
                cout<<i+diff<<" ";
                diff++;
            }
        }
    }
}
void hash_miss(int a[],int n){
    int l=1;
    int h=12;
    int q[h]={0};
    for(int i=0;i<n;i++){
        q[a[i]]++;
    }
    for(int i=l;i<=h;i++){
        if(q[i]==0)
            cout<<i<<" ";
    }
}
int main(){
    int a[5]={1,2,4,5,6};
    int b[5]={5,6,7,9,10};

    missing(a,5);
    miss1(b,5);

    int c[11]={6,7,8,9,11,12,15,16,17,18,19};
    miss2(c,11);
    cout<<endl;
    int d[10]={3,7,4,9,12,6,1,11,2,10};
    hash_miss(d,10);
    return 0;
}