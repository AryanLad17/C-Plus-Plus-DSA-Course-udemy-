#include<iostream>
#include<climits>
using namespace std;
int maxsub(int a[],int n){
    int maxsum=INT_MIN;
    int start=0;
    int end=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum+=a[k];
            }
            if(sum>maxsum){
                 maxsum=sum;
                 start=i;
                 end=j;
            }
        }
    }
    cout<<start<<" "<<end<<" ";
    return maxsum;
}
int maxsub1(int a[],int n){
    int maxsum=INT_MIN;
    int start=0;
    int end=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            
            sum+=a[j];
            if(sum>maxsum){
                 maxsum=sum;
                 start=i;
                 end=j;
            }
        }
    }
    cout<<start<<" "<<end<<" ";
    return maxsum;
}
int dpmax(int a[],int n){                       //using dyanmic programming
    int s[n];
    s[0]=a[0];
    for(int i=1;i<n;i++){
        if(s[i-1]<0)
            s[i]=a[i];
        else
            s[i]=s[i-1]+a[i];
    }
    int max=s[0];
    for(int i=1;i<n;i++){
        if(s[i]>max)
            max=s[i];
    }
    return max;
}
int kadane(int a[],int n){                       // Kadane's Max Subarray Sum
    int prevsum=a[0];
    int maxsub=a[0];  
    int start=0,end=0,substart=0;  
    for(int i=1;i<n;i++){
        if(prevsum<0){
            prevsum=a[i]; 
            substart=i;
        }
        else
            prevsum=prevsum+a[i];
        if(maxsub<prevsum){
            maxsub=prevsum;
            start=substart;
            end=i;
        }
    }
    cout<<start<<" "<<end<<" ";
    return maxsub;
}
int crosssum(int a[],int l,int mid,int h){
    int leftsub=INT_MIN,sum=0;
    for(int i=mid;i>=l;i--){
        sum+=a[i];
        if(sum>leftsub) leftsub=sum;
    }
    int rightsub=INT_MIN;
    sum=0;
    for(int i=mid+1;i<=h;i++){
        sum+=a[i];
        if(sum>rightsub) rightsub=sum;
    }
    return leftsub+rightsub;
}
int maxsub3(int a[],int l,int h){                     //using divide & conquer,
    if(l==h) return a[l];
    int mid=(l+h)/2;
    int leftmax=maxsub3(a,l,mid);
    int rightmax=maxsub3(a,mid+1,h);
    int csum=crosssum(a,l,mid,h);
    return max(max(leftmax, rightmax), csum);
}

int main(){
    int a[]={4,-5,8,-2,-1,7,-6};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<maxsub(a,n);
    cout<<endl;
    cout<<maxsub1(a,n)<<endl;
    cout<<dpmax(a,n)<<endl;
    cout<<kadane(a,n)<<endl;
    cout<<maxsub3(a,0,6)<<endl;
    return 0;
}