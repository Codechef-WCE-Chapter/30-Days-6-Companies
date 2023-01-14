#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> evaluate;
        // cout<<(stoi("-11"))<<endl;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+")
            {
                int x=evaluate.top();
                evaluate.pop();
                int y=evaluate.top();
                evaluate.pop();
                cout<<x<<" "<<y<<" "<<y+x<<endl;
                evaluate.push(x+y);
            }
            else if(tokens[i]=="-")
            {
                int x=evaluate.top();
                evaluate.pop();
                int y=evaluate.top();
                evaluate.pop();
                cout<<x<<" "<<y<<" "<<y-x<<endl;
                evaluate.push(y-x);
            }
            else if(tokens[i]=="*")
            {
                int x=evaluate.top();
                evaluate.pop();
                int y=evaluate.top();
                evaluate.pop();
                cout<<x<<" "<<y<<" "<<y*x<<endl;
                evaluate.push(x*y);
            }
            else if(tokens[i]=="/")
            {
                int x=evaluate.top();
                evaluate.pop();
                int y=evaluate.top();
                evaluate.pop();
                cout<<x<<" "<<y<<" "<<y/x<<endl;
                evaluate.push(y/x);
            }
            else evaluate.push(stoi(tokens[i]));
        }
        return evaluate.top();
        // return 1;
    }
};