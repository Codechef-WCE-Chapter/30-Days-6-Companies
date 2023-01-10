class Solution {
public:
    long long evalRPN(vector<string>& tokens) {
        stack<long long> s;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/")
            {
                if(tokens[i]=="+")
                {
                    long long a=s.top();
                    s.pop();
                    long long b=s.top();
                    s.pop();
                    s.push(b+a);
                }
                else if(tokens[i]=="*")
                {
                    long long a=s.top();
                    s.pop();
                    long long b=s.top();
                    s.pop();
                    s.push(b*a);
                }
                else if(tokens[i]=="-")
                {
                    long long a=s.top();
                    s.pop();
                    long long b=s.top();
                    s.pop();
                    s.push(b-a);
                }
                else
                {
                  long long a=s.top();
                  s.pop();
                  long long b=s.top();
                  s.pop();
                  s.push(b/a);
                } 
            }
            else
            s.push(stol(tokens[i]));
        }

        return s.top();
    }
};
