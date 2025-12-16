#include<iostream>
using namespace  std;
void Count(int a[],int n){
    int max=66;
    int count[max+1]={0};
    for(int i=0;i<n;i++)
        count[a[i]]++;
    int i=0;
    int j=0;
    while(i <= max && j < n){
        if(count[i]>0){
            a[j++]=i;
            count[i]--;
        }
        else i++;
    }
}
int main(){
    int a[]={2,5,29,7,22,9,12,1,65};
    Count(a,9);
    int n=9;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}