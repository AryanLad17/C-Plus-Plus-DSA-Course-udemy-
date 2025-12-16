#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool isOperand(char c){
    return (c>='a' && c<='z' || c>='A' && c<='Z' ||c>='0' && c<='9');
}
int para(char c){
    if(c=='^')
        return 3;
    if(c=='*' || c=='/')
        return 2;
    if(c=='+' || c=='-')
        return 1;
    return -1;
}
string infixtopostfix(string exp){
    stack<char> s;
    string pp;
    for(char c:exp){
        if(c=='(')
            s.push(c);
        else if(c==')'){
            while(!s.empty() && s.top()!='('){
                pp+=s.top();
                s.pop();
            }
        }
        else if(isOperand(c))
            pp+=c;
        else {
            while(!s.empty() && s.top()!='(' && para(c)<=para(s.top())){
                pp+=s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    while(!s.empty()){
        pp+=s.top();
        s.pop();
    }
    return pp;
}
int main(){
    string exp = "(A+B)*C-D";
    cout << "Postfix: " << infixtopostfix(exp);
    return 0;
}