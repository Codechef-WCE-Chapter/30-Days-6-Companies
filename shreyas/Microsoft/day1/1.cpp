class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>st;
        int n=tokens.size();
        /*Simply poping to stack string converting them into integer performing the operation storing into another varible then varible is get stored at top of stack at the time of storing we convert it into string as our stack is of string type so*/
        for(int i =0;i<n;i++)
        {
            if(tokens[i]=="+")
            {
                int op1=stoi(st.top());
                st.pop();
                int op2=stoi(st.top());
                st.pop();
                int op3=op1+op2;
                //op3=to_string(op3); // this will give you incomptible type because we are assigning value to int type a string which is not possible
                st.push(to_string(op3));
            }
            else if(tokens[i]=="-")
            {
                int op1=stoi(st.top());
                st.pop();
                int op2=stoi(st.top());
                st.pop();
                int op3=op2-op1;
                //op3=to_string(op3);
                st.push(to_string(op3));
            }
            else if(tokens[i]=="*")
            {
                int op1=stoi(st.top());
                st.pop();
                int op2=stoi(st.top());
                st.pop();
                int op3=op1*op2;
                //op3=to_string(op3);
                st.push(to_string(op3));
            }
           else if(tokens[i]=="/")
            {
                int op1=stoi(st.top());
                st.pop();
                int op2=stoi(st.top());
                st.pop();
                int op3=op2/op1;
               // op3=to_string(op3);
                st.push(to_string(op3));
            }
            else st.push(tokens[i]);
           
        }
        return stoi(st.top());
    }
};
