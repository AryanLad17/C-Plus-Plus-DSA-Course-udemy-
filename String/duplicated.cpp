#include<iostream>
using namespace std;
void duplicated(string s){
    int count = 0;
    for(int i = 0; i < s.length(); i++) {                           //noraml
        for(int j = i + 1; j < s.length(); j++) {
            if(s[i] == s[j]) {
                cout << s[i] << " ";
                count++;
            }
        }
    }
    cout << "\nTotal duplicates: " << count<<endl;;
}
void hash_duplicated(string s){                                         //using hashing 
    int h[26]={0};
    for(int i=0;i<s.length();i++){
        h[s[i]-97]++;
    }
    for(int i=0;i<26;i++){
        if(h[i]>1){
            cout<<char(i+97)<<" is duplicated "<<h[i]<<" times"<<endl;
        }
    }
}
void bitwise_duplicated(string s){
    long int h=0,x=0;
    for(int i=0;i<s.length();i++){
        x=1;
        x=x<<(s[i]-'a');
        if((x&h)>0)
            cout<<s[i]<<" is duplicated"<<endl;
         else 
             h=x|h;
    }
}
int main() {
    string s = "finding";
    duplicated(s);
    hash_duplicated(s);
    bitwise_duplicated(s);
    return 0;
}
