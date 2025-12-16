#include<iostream>
using namespace std;
void get(int a[],int n,int index){
    if(index>=0 && index<n)
        cout<<a[index];
}
void set(int a[],int n,int index,int x){
    if(index>=0 && index<n)
        a[index]=x;
}
void max(int a[],int n){
    int max=a[0];
    for(int i=1;i<n;i++){
        if(a[i]>max)
            max=a[i];
    }
    cout<<max;
}
void min(int a[],int n){
    int min=a[0];
    for(int i=1;i<n;i++){
        if(a[i]<min)
            min=a[i];
    }
    cout<<min;
}
void sum(int a[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    cout<<sum;
}
void avg(int a[],int n){
    int sum=0;
    double avg=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        avg=sum/n;
    }
    cout<<avg;
}
int main(){
    int a[5]={2,4,5,7,8};
    get(a,5,3);
    cout<<endl;
    set(a,5,3,90);
    max(a,5);
    cout<<endl;
    min(a,5);
    cout<<endl;
    sum(a,5);
    cout<<endl;
    avg(a,5);
}