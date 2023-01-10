class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // long long int ans=0;
        stack<long long int> s;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"){
                long long int a = s.top();
                s.pop();
                long long int b = s.top();
                s.pop();
                s.push(a+b);
            }
            else if(tokens[i]=="-"){
                long long int a = s.top();
                s.pop();
                long long int b = s.top();
                s.pop();
                s.push(b-a);
            }
            else if(tokens[i]=="*"){
                long long int a = s.top();
                s.pop();
                long long int b = s.top();
                s.pop();
                s.push(a*b);
            }
            else if(tokens[i]=="/"){
                long long int a = s.top();
                s.pop();
                long long int b = s.top();
                s.pop();
                s.push(b/a);
            }
            else{
                long long int x = stoi(tokens[i]);
                s.push(x);
            }
        }
        return s.top();
    }
};