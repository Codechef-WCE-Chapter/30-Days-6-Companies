#include<stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        //recursive method:
        // string t = tokens.back();
        // tokens.pop_back();
        // if(t != "+" && t != "-" && t != "*" && t != "/") return stoi(t);
        // else{
        //     long long int b = evalRPN(tokens);
        //     long long int a = evalRPN(tokens);
        //     if(t == "+") return a + b;
        //     else if(t == "-") return a - b;
        //     else if(t == "*") return a * b;
        //     else return a / b;
        // }

        //iterative method:
        stack<long long int>st;
        for(int i = 0;i<tokens.size();i++){
            string t = tokens[i];
            if(t != "+" && t != "-" && t != "*" && t != "/"){
                st.push(stoi(t));
                cout<<st.top()<<" ";
            }
            else{
                long long int b = st.top();
                st.pop();
                long long int a = st.top();
                st.pop();

                if(t == "+")st.push(a+b);
                else if(t == "-")st.push(a-b);
                else if(t == "*")st.push(a*b);
                else st.push(a/b);
                cout<<st.top()<<" ";
            }
        }
        long long int ans = st.top();
        return ans;
    }
};