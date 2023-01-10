class Solution {
public:

    int evalRPN(vector<string>&s) {
        stack<int> st;
        int n = s.size();
        
        for(int i=0; i<n; i++){
            // int s = stoi(tokens[i]);
            if(s[i]=="+" || s[i]=="-" || s[i]=="*" || s[i]=="/"){
                int x1 = st.top();
                st.pop();
                int x2 = st.top();
                st.pop();

                if(s[i]=="+") st.push(x2+x1);
                else if(s[i]=="-") st.push(x2-x1);
                else if(s[i]=="*") st.push(x2*x1);
                else st.push(x2/x1);

            }
            else{
                st.push(stoi(s[i]));
            }
        }
        return st.top();
    }
};
