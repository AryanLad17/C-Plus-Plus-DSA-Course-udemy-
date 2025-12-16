#include<iostream>
#include<set>
#include<vector>
using namespace std;
void union1(int a[],int b[],int n){
    vector<int> r;
    int i=0,j=0;
    while(i<n && j<n){
        if(a[i]<b[j]){
            r.push_back(a[i]);
            i++;
        }
        else if(a[i]>b[j]){
            r.push_back(b[j]);
            j++;
        }
        else{
            r.push_back(a[i]);
            i++;
            j++;
        }
    }
    while(i<n){
        r.push_back(a[i]);
        i++;
    }
    while(j<n){
        r.push_back(b[j]);
        j++;
    }
    for(int i=0;i<8;i++)
        cout<<r[i]<<" ";
}
void intersection(int a[],int b[],int n){
    vector<int> r;
    int i=0,j=0;
    while(i<n && j<n){
        if(a[i]<b[j])
            i++;
        else if(a[i]>b[j])
            j++;
        else {
            r.push_back(b[j]);
            i++;
            j++;
        }
    }
    while(i<n){
        r.push_back(a[i]);
        i++;
    }
    while(j<n){
        r.push_back(b[j]);
        j++;
    }
    for(int i=0;i<2;i++)
        cout<<r[i]<<" ";
}
void difference(int a[],int b[],int n){
    vector<int> r;
    int i=0,j=0;
    while(i<n && j<n){
        if(a[i]<b[j]){
            r.push_back(a[i]);
            i++;
        }
        else if(a[i]>b[j]){
            r.push_back(b[j]);
            j++;
        }
        else{ 
            i++;
            j++;
        }
    }
    while(i<n){
        r.push_back(a[i]);
        i++;
    }
    while(j<n){
        r.push_back(b[j]);
        j++;
    }
    for(int i=0;i<6;i++)
        cout<<r[i]<<" ";
}
int main(){
    int a[5]={3,4,5,6,10};
    int b[5]={2,4,5,7,12};
    union1(a,b,5);
    cout<<endl;
    intersection(a,b,5);
    cout<<endl;
    difference(a,b,5);
    return 0;
}