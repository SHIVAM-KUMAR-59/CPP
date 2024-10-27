/*
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
*/

#include<iostream>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open,star;
        for(int i=0;i<s.length();i++){
            if(s[i]==')'){
                if(open.empty()){
                    if(star.empty()) return false;
                    else star.pop();
                }
                else open.pop();
            }
            else if(s[i]=='('){
                open.push(i);
            }
            else star.push(i);
        }
        while(!open.empty()){
            if(star.empty() || open.top()>star.top()) return false;
            else {
                star.pop();
                open.pop();
            }
        }
        return true;
    }
};