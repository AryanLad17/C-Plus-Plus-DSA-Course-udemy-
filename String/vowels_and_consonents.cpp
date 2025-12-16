#include<iostream>
#include<string>
using namespace std;
int main(){
    string s="How are you bro";
    
    int vcount=0;
    int ccount=0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='a' ||s[i]=='i' || s[i]=='e' ||s[i]=='o' || s[i]=='u'||
           s[i]=='A' ||s[i]=='I' || s[i]=='E' ||s[i]=='O' || s[i]=='U')
            vcount++;
        else if((s[i]>='a' && s[i]<='z') || 
                (s[i]>='A' && s[i]<='Z'))
            ccount++;
    }
    cout<<vcount<<" "<<ccount;
}