long long perform(char ch,long long  a,long long  b){
    if(ch=='+') return a+b;
    else if(ch=='*') return a*b;
    else if(ch=='-') return b-a;
    else return b/a;
}
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    stack<long long>st;
    for(int i=0;i<tokens.size();i++){
        if(tokens[i]=="+" || tokens[i]=="*" || tokens[i]=="-" || tokens[i]=="/"){
        long long a=st.top();st.pop();
        long long b=st.top();st.pop();
        st.push(perform(tokens[i][0],a,b));
        }
        else{
        long long  n=stoi(tokens[i]);
        st.push(n);
        }
    }
    return st.top();
    }
};
