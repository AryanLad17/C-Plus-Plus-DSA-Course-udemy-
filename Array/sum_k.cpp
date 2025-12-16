#include<iostream>
using namespace std;
void sum1(int a[],int n,int k){
    for(int  i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]+a[j]==k){
                cout << "At index " << i << " and " << j
                     << " the element sum is " << k << endl;
            }
        }
    }
}
void hash_sum(int a[],int n,int k){
    int h[14]={0};
    for(int i=0;i<n;i++){  
        if(h[k-a[i]]!=0)    
            cout << a[i] << " & " << k - a[i] << endl;
        h[a[i]]++;
    }
}
void sorted(int a[],int n,int k){
    int i=0,j=n-1;
    while(i<j){
        if(a[i]+a[j]==k){
            cout<<"The index "<<i<<" and "<<j<<" sum to "<<k;
            i++;
            j--;
        }
        else if(a[i]+a[j]>k)
            j--;
        else 
            i++;
    }
}
int main(){
    int a[7]={2,5,7,13,3,9,6};
    sum1(a,7,12);
    cout<<endl;
    hash_sum(a,7,12);
    int b[8]={3,4,5,6,8,9,10,14};
    sorted(b,8,10);
}