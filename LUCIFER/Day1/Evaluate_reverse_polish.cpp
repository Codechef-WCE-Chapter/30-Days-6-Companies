class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int>check;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/")
            {
                int b=check[check.size()-1];
                check.pop_back();
                int a=check[check.size()-1];
                check.pop_back();
                if(tokens[i]=="+")
                   check.push_back(a+b);
                else if(tokens[i]=="-")
                   check.push_back(a-b);
                else if(tokens[i]=="*")
                   check.push_back(a*b);
                else
                   check.push_back(a/b);
            }
            else
            {
                int x=stoi(tokens[i]);
                check.push_back(x);
            }
        }
        return check[0];
    }
};
