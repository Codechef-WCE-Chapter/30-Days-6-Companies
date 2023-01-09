class Solution{
public:
    int evalRPN(vector<string>& tokens){
        stack<int> S;
        for(auto token : tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int first = S.top(); S.pop();
                int second = S.top(); S.pop();

                if(token == "+") S.push(second + first);
                else if(token == "-") S.push(second - first);
                else if(token == "*") S.push(second * first);
                else if(token == "/") S.push(second / first);
            }
            else S.push(stoi(token));
        }

        return S.top();
    }
};
