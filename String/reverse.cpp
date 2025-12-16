#include<iostream>
#include<string>
using namespace std;
int main(){
    string s="python";
    string a="";
    int i;
    for( i=0;s[i]!='\0';i++){}
    i=i-1;
    for(int j=0;i>=0;i--,j++){
        a[j]=s[i];
    }
    cout<<a;
}