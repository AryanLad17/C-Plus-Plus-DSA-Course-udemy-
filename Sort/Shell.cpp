#include<iostream>
using namespace std;
template<typename T>
void shellsort(T a[100],T n){
	for(int gap=n/2;gap>0;gap/=2){
		for(int i=gap;i<n;i++){
			int key=a[i];
			int j=i-gap;
			for(;j>=0;j-=gap){
				if(a[j]>key){
					a[j+gap]=a[j];
				}
				else {break;}
			}
			a[j+gap]=key;
		}
	}
}
int main(){
    int a[]={2,5,29,7,22,9,12,1,65};
    shellsort(a,9);
    int n=9;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}