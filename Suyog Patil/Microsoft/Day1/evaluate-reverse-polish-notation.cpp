class Solution
{
public:
    void printSt(stack<int> st)
    {
        while (not st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << "\n";
    }

    int evalRPN(vector<string> &s)
    {
        stack<long long int> st;
        for (string ss : s)
        {
            if (ss != "+" and ss != "-" and ss != "*" and ss != "/")
                st.push(stoi(ss));
            else
            {
                long long int a = st.top();
                st.pop();
                long long int b = st.top();
                st.pop();

                // cout << a << " " << b << "\n";
                if (ss == "+")
                    st.push(a + b);
                else if (ss == "-")
                    st.push(b - a);
                else if (ss == "*")
                    st.push(a * b);
                else if (ss == "/")
                    st.push(b / a);
            }
            // printSt(st);
        }
        return st.top();
    }
};
