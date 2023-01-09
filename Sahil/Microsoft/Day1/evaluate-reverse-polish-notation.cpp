class Solution
{
public:
    long long evalRPN(vector<string> &tokens)
    {
        string t = tokens.back();
        tokens.pop_back();
        if (t != "+" && t != "-" && t != "*" && t != "/")
        {
            return stoi(t);
        }
        else
        {
            long long b = evalRPN(tokens);
            long long a = evalRPN(tokens);
            if (t == "+")
                return a + b;
            else if (t == "-")
                return a - b;
            else if (t == "*")
                return a * b;
            else
                return a / b;
        }
    }
};