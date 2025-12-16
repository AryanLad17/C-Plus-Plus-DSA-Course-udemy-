#include<iostream>
using namespace std;
int knap(int p[],int w[],int n,int m){
    if(n==0 || m==0)
        return 0;
    if(w[n-1]<=m){
        int no=knap(p,w,n-1,m);
        int yes= p[n-1] +knap(p,w,n-1,m-w[n-1]);
        return no>yes?no:yes;
    }
    else {
        return knap(p,w,n-1,m);
    }
}
int Knap(int p[],int w[],int n,int m){      //using memoization, recursion, and tabulation
    int t[n+1][m+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            t[i][j]=-1;
        }
    }
    if(n==0 || m==0){
        t[n][m]=0;
        return 0;
    }// missing:
    if(t[n][m] != -1) return t[n][m];
    if(w[n-1]<=m){
        int no=Knap(p,w,n-1,m);
        int yes= p[n-1] +Knap(p,w,n-1,m-w[n-1]);
        t[n][m]= no>yes?no:yes;
    }
    else
        t[n][m]=knap(p,w,n-1,m);
    return t[n][m];
    
}
int Knap1(int p[],int w[],int n,int m){                   
    int t[n+1][m+1];
    
    for(int j = 0; j <= m; j++) t[0][j] = 0;
    for(int i = 0; i <= n; i++) t[i][0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(w[i-1] <= j)
                t[i][j]=max(t[i-1][j],t[i-1][j-w[i-1]]+p[i-1]);
            else
                t[i][j] = t[i-1][j];

        }
    }
    return t[n][m];
}
int main(){
    int p[4]={6,5,3,8};
    int w[4]={1,2,1,2};
    int m=5;
    int n=4;
    cout<<knap(p,w,4,5);
    cout<<Knap(p,w,4,5);
    cout<<endl;
    cout<<Knap1(p,w,4,5);
    return 0;
}