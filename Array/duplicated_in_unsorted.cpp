#include<iostream>
using namespace std;
void hash1(int a[],int n){
    int high=20;
    int h[21]={0};
    for(int i=0;i<n;i++)
        h[a[i]]++;
    for(int i=0;i<=20;i++){
        if(h[i]>1)
            cout << i << " appears " << h[i] << " times\n";
    }
}
int main(){
    int a[10]={3,11,8,8,10,15,12,15,15,20};
    hash1(a,10);
    return 0;
}