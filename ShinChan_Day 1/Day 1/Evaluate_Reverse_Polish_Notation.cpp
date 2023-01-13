class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack <string> s;
        for(int i=0;i<t.size();i++){
            if(t[i]=="+" || t[i]=="-" || t[i]=="*" || t[i]=="/"){
                long long int b=stoll(s.top());  s.pop();
                long long int a=stoll(s.top());  s.pop();
                long long int r=0;
                if(t[i]=="+") r = a + b;
                else if(t[i]=="-") r = a - b;
                else if(t[i]=="*") r = a * b;
                else if(t[i]=="/") r = a / b;
                s.push(to_string(r));
            }
            else s.push(t[i]);
        }
        return stoi(s.top());
    }
};
