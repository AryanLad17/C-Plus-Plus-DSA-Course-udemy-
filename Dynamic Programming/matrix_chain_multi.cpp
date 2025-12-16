#include<iostream>
#include<climits>
using namespace std;
int m(int d[],int i,int j){
    if(i>=j) return 0;
    int mincost=INT_MAX;
    for(int k=i;k<j;k++){
        int cost=m(d,i,k)+m(d,k+1,j)+d[i-1]*d[k]*d[j];
        if(cost<mincost) mincost=cost;
    }
    return mincost;
}
int main(){
    int d[]={3,2,4,2,5};
    cout<<m(d,1,4);
}