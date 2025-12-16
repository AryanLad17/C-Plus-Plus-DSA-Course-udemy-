#include<iostream>
#include <algorithm>
using namespace std;
void duplicated(int a[],int n){
    int last=0;
    for(int i=0;i<n;i++){
        if(a[i]==a[i+1] && a[i]!=last){
            cout<<a[i]<<" ";
            last=a[i];
        }
    }
}
void cout_duplicated(int a[],int n){
    int count=0;
    for(int i=0;i<n-1;i++){
        if(a[i]==a[i+1]){
            int j=i+1;
            while(a[j]==a[i]) j++;
            cout<<a[i]<<" is "<<j-i<<" times duplicated"<<endl;
            i=j-1; 
        }
    }
}
void hash_duplicated(int a[],int n){
    int high =20;
    int h[21]={0};
    for(int i=0;i<n;i++)
        h[a[i]]++;
    for(int i=0;i<=20;i++){
        if(h[i]>1)
            cout << i << " appears " << h[i] << " times\n";
    }
}
int main(){
    int a[10]={3,6,8,8,10,12,15,15,15,20};
    duplicated(a,10);
    cout<<endl;
    cout_duplicated(a,10);
    cout<<endl;
    hash_duplicated(a,10);
    return 0;
}
