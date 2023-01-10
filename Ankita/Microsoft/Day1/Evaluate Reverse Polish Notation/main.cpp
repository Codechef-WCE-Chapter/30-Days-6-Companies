#include<bits/stdc++.h>
using namespace std;

class Solution {
private:

bool symbol(string c){
    if(c=="*" || c=="/" || c=="+" || c=="-"){
        return true;
    }
    return false;
}

int calculate(string c, int a, int b){
    if(c=="*"){
        return a*b;
    }
    else if(c=="/"){
        return b/a;
    }
    else if(c=="+"){
        return a+b;
    }
    else{
        return b-a;
    }
}
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(int i=0; i<tokens.size(); i++){
            if(!symbol(tokens[i])){
                st.push(tokens[i]);
            }
            else{
                int a = stoi(st.top());
                st.pop();
                int b = stoi(st.top());
                st.pop();
                st.push(to_string(calculate(tokens[i], a, b)));
            }
        }
        return stoi(st.top());
    }
};

int main(){
    Solution sol;
    int n;
    vector<string> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    cout<<sol.evalRPN(v);
}