#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool isOperand(char c){
    return (c>='0' && c<='9');
}
// int para(char c){
//     if(c=='^')
//         return 3;
//     if(c=='*' || c=='/')
//         return 2;
//     if(c=='+' || c=='-')
//         return 1;
//     return -1;
// }
int eval(string exp){
    stack<int> s;
    for(char c:exp){
        if(isOperand(c))
            s.push(c-'0');
        else{
            int x2=s.top(); s.pop();
            int x1=s.top(); s.pop();
            int r;
            switch(c){
                case '+': 
                    r=x1+x2; 
                    break;
                case '-': 
                    r=x1-x2; 
                    break;
                case '*': 
                    r=x1*x2; 
                    break;
                case '/': 
                    r=x1/x2; 
                    break;
                default:
                    break;
            }
            s.push(r);
        }
    }
    return s.top();
    s.pop();
}
int main(){
    string exp="53+62/*9-";
    cout<<eval(exp);
    return 0;
}