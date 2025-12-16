#include<iostream>
using namespace std;
void Insertion(int a[],int n){
    for(int i=1;i<n;i++){
        int j=i-1;
        int key=a[i];
        while(j>=0 && a[j]>key){
            a[j+1] = key;
            j--;
        }
        a[j+1]=key;
    }
}
int main(){
    int a[]={2,5,29,7,22,9,12,1,65};
    Insertion(a,9);
    int n=9;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}