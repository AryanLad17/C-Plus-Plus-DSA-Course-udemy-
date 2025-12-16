#include<iostream>
#include<cmath>
#include <cstdlib>
using namespace std;
void Perm(char str[],char res[],int n,bool sel[],int k){
    
    if(k==n){
        for(int i=0;i<n;i++)
            cout<<res[i];        
        cout<<endl;
    }
    else{
        for(int i=0;i<n;i++){
            if(sel[i]==false){
                res[k]=str[i];
                sel[i]=true;
                Perm(str,res,n,sel,k+1);
                sel[i]=false;
            }
        }
    }
}
void Perm1(char str[],char res[],int n,bool sel[],int k){        //using bounding function 
    
    if(k==n){
        for(int i=0;i<n;i++)
            cout<<res[i];        
        cout<<endl;
    }
    else{
        for(int i=0;i<n;i++){
            if(sel[i]==false){
                if(k>0 && abs(str[i] - res[k-1])==1) continue;
                res[k]=str[i];
                sel[i]=true;
                Perm1(str,res,n,sel,k+1);
                sel[i]=false;
            }
        }
    }
}
int main(){
    int n=3;
    char str[]={'a','b','c'};
    char res[4];
    res[n] = '\0';
    bool sel[3];
    for(int i=0;i<n;i++)
        sel[i]=false;
    // Perm(str,res,n,sel,0);
    cout<<endl;
    Perm1(str,res,n,sel,0);
    return 0;
}