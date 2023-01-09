class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> s;
        for(auto x: tokens)
        {
            if(x == "+" || x == "-" || x == "*" || x == "/")
            {
                long long  secondNum = s.top(); s.pop();
                long long  firstNum = s.top(); s.pop();

                if(x == "+")
                {
                    s.push(firstNum + secondNum);
                }
                if(x == "-")
                {
                    s.push(firstNum - secondNum);
                }
                if(x == "*")
                {
                    s.push(firstNum * secondNum);
                }
                if(x == "/")
                {
                    s.push(firstNum / secondNum);
                }
            }
            else
            {
                stringstream ss(x);
                long long ans;
                ss >> ans;
                s.push(ans);
            }
        }
        return s.top();
    }
};