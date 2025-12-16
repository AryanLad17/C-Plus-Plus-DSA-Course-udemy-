#include<iostream>
#include<vector>
using namespace std;
void merge(int a[],int b[],int n,int m){
    vector<int> c;
    int i=0,j=0;
    while(i<n && j<m)   {
        if(a[i]<b[j]){
            c.push_back(a[i]);
            i++;
        }
        else if(a[i]>b[i]){
            c.push_back(b[j]);
            j++;
        }
        else{
            c.push_back(a[i]);
            i++;
            j++;
        }
    }
    while(i<n){
        c.push_back(a[i]);
        i++;
    }
    while(j<m){
        c.push_back(b[j]);
        j++;
    }
    for(int i=0;i<10;i++)
        cout<<c[i]<<" ";
    
}
int main(){
    int a[5]={23,45,67,78,90};
    int b[6]={2,4,6,7,90,100};
    merge(a,b,5,6);
   
}