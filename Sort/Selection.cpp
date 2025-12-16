#include<iostream>
using namespace std;
void Selection(int a[],int n){
    int j,k;
    for(int i=0;i<n-1;i++){
        for(j=k=i;j<n;j++){
            if(a[j]<a[k])
                k=j;
        }
        swap(a[i],a[k]);
    }
}
int main(){
    int a[]={2,5,29,7,22,9,12,1,65};
    Selection(a,9);
    int n=9;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}