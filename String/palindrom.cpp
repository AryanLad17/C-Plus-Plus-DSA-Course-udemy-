#include<iostream>
using namespace std;
int main(){
    string s="pnap";
    int i=0;
    int j=s.length()-1;
    while(i<j){
        if(s[i]!=s[j]){
            cout<<" not IT is palindrom";
            return 0;
        }
        i++;
        j--;
        
    }
    cout<<"IT is palindrom";
    return 0;
}