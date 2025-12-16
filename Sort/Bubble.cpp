#include<iostream>
using namespace std;
void Bubble(int a[],int n){
    int flag;
    for(int i=0;i<n-1;i++){
    
        for(int j=0;j<n-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                flag++;
            }
        }
        if(flag==0) break;
    }
}
int main(){
    int a[]={2,5,29,7,22,9,12,1,65};
    Bubble(a,9);
    int n=9;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}