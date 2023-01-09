class Solution {
public:
    bool isOperator(string ch){
        if(ch=="+"||ch=="-"||ch=="*"||ch=="/"){
            return true;
        }
        return false;
    }
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<string> st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(tokens[i]);
            }
            else{
                if(isOperator(tokens[i])){
                    string ch=tokens[i];
                    long long b=stoll(st.top());
                    st.pop();
                    long long a=stoll(st.top());
                    st.pop();
                    if(ch=="+"){
                        st.push(to_string(a+b));
                    }
                    if(ch=="-"){
                        st.push(to_string(a-b));
                    }
                    if(ch=="*"){
                        st.push(to_string(a*b));
                    }
                    if(ch=="/"){
                        st.push(to_string(a/b));
                    }
                }
                else{
                    st.push(tokens[i]);
                }
            }
        }
        return stoll(st.top());
    }
};