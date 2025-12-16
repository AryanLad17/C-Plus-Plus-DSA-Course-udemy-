#include<iostream>
using namespace std;
int Quciksort(int a[],int start,int end){
    int pivot=a[start];
    int high=end;
    int low=start+1;
    while(true){
        while(low<=high && pivot>=a[low])
            low++;
        while(low<=high && pivot<a[high])
            high--;
        if(low>high)
		    break;
		swap(a[low],a[high]);
    }
    swap(a[start],a[high]);
    return high;
}
void quick(int a[],int start,int end){
    int j;
	if(start<end){
		j=Quciksort(a,start,end);
		quick(a,start,j-1);
		quick(a,j+1,end);
	}
}
int main(){
    int a[]={2,5,29,7,22,9,12,1,65};
    quick(a,0,8);
    int n=9;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}