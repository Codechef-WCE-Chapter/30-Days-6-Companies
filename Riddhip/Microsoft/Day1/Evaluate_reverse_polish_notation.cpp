class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int>st;
        
        for(long int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+" && !st.empty())
            {
               long int x=st.top();
                st.pop();
                long int y=st.top();
                st.pop();
               long int count=x+y;
                st.push(count);

            }
            else if(tokens[i]=="*"&& !st.empty())
            {
                long int x=st.top();
                st.pop();
                long int y=st.top();
                st.pop();
                long int count=x*y;
                st.push(count);

            }
            else if(tokens[i]=="/"&& !st.empty())
            {
                long int x=st.top();
                st.pop();
                long int y=st.top();
                st.pop();
                long int count=y/x;
                st.push(count);

            }
            else if(tokens[i]=="-"&& !st.empty())
            {
                long int x=st.top();
                st.pop();
                long int y=st.top();
                st.pop();
                long int count=y-x;
                st.push(count);

            }
            else st.push(stoi(tokens[i]));
        }
        return st.top();
    }
};