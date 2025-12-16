#include<iostream>
using namespace std;
void max_min(int a[],int n){
    int max=a[0];
    int min=a[0];
    for(int i=1;i<n;i++){
        if(a[i]>max)
            max=a[i];
        else if(a[i]<min)
            min=a[i];
    }
    cout<<max<<" "<<min;
}
int main(){
    int a[6]={2,65,1,90,68,4};
    max_min(a,6);
}