class Solution {
public:
    int evalRPN(vector<string>& s) {
        stack<int>st; //Intializing the stack 
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=="/" or s[i]=="*" or s[i]=="+" or s[i]=="-") 
            {
                long long k1=st.top();
                st.pop();
                long long k2=st.top();
                st.pop();


                if(s[i]=="/")
                    st.push((int)(k2/k1));
                if(s[i]=="*")
                    st.push((int)(k2*k1));
                if(s[i]=="+")
                    st.push((int)(k2+k1));
                if(s[i]=="-")
                    st.push((int)(k2-k1));
            }
            else
            {
                st.push(stoi(s[i]));
            }
        }

        return st.top();
    }
};