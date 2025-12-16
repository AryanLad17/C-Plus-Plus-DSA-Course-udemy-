#include<iostream>
#include<string>
using namespace std;
void anagram(string s,string a){
    int h[26]={0};
    if(s.length()!=a.length()){
        cout<<"Not Anagram";
        return;
    }
    else{
        for(int i=0;i<s.length() && a.length() ;i++){
            h[s[i]-'a']++;
            h[a[i]-'a']--;
        }
        // for(int i=0;i<a.length();i++){
        //     h[a[i]-'a']--;
        // }
        for(int i=0;i<26;i++){
            if(h[i] != 0){
                cout << "Not Anagram";
                return;
            }
        }
        cout << "Anagram";
    }
}
int main(){
    string s="verbose";
    string a="observe";
    anagram(s,a);
    return 0;
}