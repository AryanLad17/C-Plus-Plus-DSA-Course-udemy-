#include<iostream>
#include<string>
#include <cctype>
using namespace std;
int main(){
    char n[]={'j','o','h','n','\0'};
    cout<<n;

    char a[]="WelcoMe";
    int i;
    for(i=0;a[i]!='\0';i++){}
    cout<<i;
    // a=toupper(a);

    for(int i=0;a[i]!='\0';i++){
        if(a[i]>='A' && a[i]<='Z')
            a[i]+=32;
        else if(a[i]>='a' && a[i]<='z')
            a[i]-=32;
    }
    cout<<a;
    return 0;
}