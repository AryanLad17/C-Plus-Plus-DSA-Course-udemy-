#include<iostream>
using namespace std;
void merge(int a[], int start, int mid,int end){
	int len1=mid-start+1;
	int len2=end-mid;
	int* leftarray=new int[len1];
	int* rightarray=new int[len2];
	for(int i=0;i<len1;i++)
		leftarray[i]=a[start+i];		
	for(int j=0;j<len2;j++)
		rightarray[j]=a[mid+j+1];	
	int i=0,j=0;
	while(i<len1 && j<len2){
		if(leftarray[i]<rightarray[j])
			a[start++]=leftarray[i++];
		else 
			a[start++]=rightarray[j++];
	}
	while(i<len1)
		a[start++]=leftarray[i++];
	while(j<len2)
		a[start++]=rightarray[j++];
	delete[] leftarray;
	delete[] rightarray;
}
void mergesort(int a[],int start,int end){
	int mid=(start+end)/2;
	if(start<end){
		mergesort(a,start,mid);
		mergesort(a,mid+1,end);
		merge(a,start,mid,end);
	}
}
int main(){
    int a[]={2,5,29,7,22,9,12,1,65};
    mergesort(a,0,8);
    int n=9;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}