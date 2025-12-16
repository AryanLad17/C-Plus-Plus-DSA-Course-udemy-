#include<iostream>
using namespace std;
void reverse(int a[],int n){
    int b[n];
    int i;
    int j;
    for(i=n-1,j=0;i>=0;i--,j++)
        b[j]=a[i];
    for(int i=0;i<n;i++)
        a[i]=b[i];
}
void reverse1(int a[], int n) {
    int i, j, temp;
    for (i = 0, j = n - 1; i < j; i++, j--) {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}
void left_shfit(int a[],int n){
    for(int i=0;i<n;i++){
        a[i-1]=a[i];
        a[n]=0;
    }
}
int main(){
    int a[5]={5,7,2,4,7};
    // reverse(a,5);
    // for(int i=0;i<5;i++)
    //     cout<<a[i]<<" ";
    // cout<<endl;
    // reverse1(a,5);
    // for(int i=0;i<5;i++)
    //     cout<<a[i]<<" ";
    left_shfit(a,5);
    for(int i=0;i<4;i++)
        cout<<a[i]<<" ";
    return 0;
}