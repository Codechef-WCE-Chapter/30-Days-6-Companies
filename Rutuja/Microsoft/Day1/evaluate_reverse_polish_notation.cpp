/*Evaluate Reverse Polish Notation: https://leetcode.com/problems/evaluate-reverse-polish-notation/description/ */

#include<bits/stdc++.h>
using namespace std;

//Note: Problem of expression parsing --> solved using Stack


// Approach 1: Use of Stack
// T.C: O(n)
// S.C: O(n) -> Stack 

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        int n1=0, n2=0, res=0;
        for(int i=0; i<tokens.size(); i++)
        {
            if(tokens[i]!= "+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/" )
            st.push(tokens[i]);
            else
            {
                //main logic
                n1=stoi(st.top() );
                st.pop();
                n2=stoi(st.top() );
                st.pop();

                if(tokens[i]=="+")
                {
                st.push(to_string(n1+n2));
                }
                else if(tokens[i]=="-")
                {
                st.push(to_string((n2-n1) ));
                }
                else if(tokens[i]=="*")
                {
                st.push(to_string(n1*n2));
                }
                else if(tokens[i]=="/")
                {
                st.push(to_string(  n2/n1 ) );
                }
            }
        }
        res= stoi(st.top());
        return res;
    }
};