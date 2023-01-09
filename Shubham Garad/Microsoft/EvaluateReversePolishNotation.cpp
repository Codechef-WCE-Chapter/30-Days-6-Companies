#define ll long long
class Solution
{
    public:
        ll cal(ll num1 ,ll num2, char &op)
        {
            switch (op)
            {

                case '+':
                    return num1 + num2;
                    break;

                case '-':
                    return num1 - num2;
                    break;

                case '*':
                    return num1 * num2;
                    break;

                case '/':
                    return num1 / num2;
                    break;
            }
            return 0;
        }
    ll evalRPN(vector<string> &tokens)
    {
        stack<ll> s;
        for (auto &i: tokens)
        {
            if (i == "-"
                or i == "+"
                or i == "*"
                or i == "/")
            {
                ll a = s.top();
                s.pop();
                ll b = s.top();
                s.pop();
                s.push(cal(b, a, i[0]));
            }
            else
            {
                s.push(stoi(i));
            }
        }
        return s.top();
    }
};