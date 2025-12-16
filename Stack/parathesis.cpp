#include<iostream>
#include<stack>
using namespace std;
bool check(string exp){
    stack<char> s;
    for(char c:exp){
        if(c=='(' || c=='['|| c=='{')
            s.push(c);
        if(c==')' || c==']'|| c=='}'){
            if(s.empty()) return false;
            char top=s.top();
            s.pop();
            if(c=='(' && top!=')') return false;
            if(c=='{' && top!='}') return false;
            if(c=='[' && top!=']') return false;
        }
    }
    // return s.empty();
}
int main(){
    stack<char> s;
    string exp="{)}";
   if (check(exp))
        cout << "Balanced";
    else
        cout << "Not Balanced";
        
    return 0;
}