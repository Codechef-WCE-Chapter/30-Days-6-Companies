#define ll long long int

class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<ll>st;
        
        for(auto sp:tokens)
        {
            if(sp=="+") 
            {
                long long int b = st.top(); 
                st.pop();
                long long int a = st.top(); 
                st.pop();
                st.push(a+b);
            }
            else if(sp=="-") 
            {
                long long int b = st.top(); 
                st.pop();
                long long int a = st.top(); 
                st.pop();
                st.push(a-b);
            }
            else if(sp=="*") 
            {
                long long int b = st.top(); 
                st.pop();
                long long int a = st.top(); 
                st.pop();
                st.push(b*a);
            }
            else if(sp=="/") 
            {
                long long int b = st.top(); 
                st.pop();
                long long int a = st.top(); 
                st.pop();
                st.push(a/b);
            }
            else
            {
                st.push(stoi(sp));
            }
               
        }

        return st.top();
    }
};