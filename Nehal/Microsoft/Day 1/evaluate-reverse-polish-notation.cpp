class Solution
{
public:
    long long calc(long long a, long b, string op)
    {
        // cout<<type(op)<<endl;
        // switch(op){
        //     case "+" : return a + b;
        //     case "-" : return a - b;
        //     case "*" : return a * b;
        //     case "/" : return a / b;
        // }
        // long long ans =  a * b;
        if (op == "+")
            return a + b;
        if (op == "-")
            return a - b;
        if (op == "*")
            return a * b;
        if (op == "/")
            return a / b;
        return 0;
    }
    int evalRPN(vector<string> &tokens)
    {
        stack<string> st;
        string match = "+-*/";
        for (auto it : tokens)
        {
            if (match.find(it) != string::npos)
            {
                string a = st.top();
                st.pop();
                string b = st.top();
                st.pop();
                st.push(to_string(calc(stoll(b), stoll(a), it)));
            }
            else
            {
                st.push(it);
            }
        }
        //    int ans = st.top();
        return stoi(st.top());
    }
};