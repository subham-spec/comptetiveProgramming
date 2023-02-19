#include <bits/stdc++.h>
using namespace std;
bool isValid(string s) {
    stack<int> ar;
        
    for(int i=0; i<s.size(); i++) {
        char c = s[i];
        if(c == '[' || c == '{' || c == '(') 
            ar.push(c);
        else{
            if(ar.empty())
                   return false;
            char ch = ar.top();
            if((c==']'&& ch=='[') || (c=='}' && ch=='{') || (c==')' && ch=='('))
                ar.pop();
            else
                return false;
        } 
    }
    return ar.empty();
}
int main(){
    
}
