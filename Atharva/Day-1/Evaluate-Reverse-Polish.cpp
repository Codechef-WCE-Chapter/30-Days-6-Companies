class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> s;
        string a;
        long long c = 0;
        int flag = 0;
        long long b;
        for(int i = 0;i<tokens.size();++i){
            a = tokens[i];
            c = 0;
            flag = 0;
            
            if(a == "*"){
                    b = s.top();
                    s.pop();
                    b = b*s.top();
                    s.pop();
                    s.push(b);
            }    
            else if(a == "+"){
                    
                    b = s.top();
                    s.pop();
                    b = b+s.top();
                    s.pop();
                    s.push(b);
            }
            else if(a== "/"){
                    
                    b = s.top();
                    s.pop();
                    b = s.top()/b;
                    s.pop();
                    s.push(b);
            }
            else if(a == "-"){
                    
                    b = s.top();
                    s.pop();
                    b = s.top()-b;
                    s.pop();
                    s.push(b);
            }
            else{
                    if(tokens[i][0] == '-'){
                        a = tokens[i].substr(1,tokens[i].size()-1);
                        flag = 1;
                    }
                    c = stol(a);
                    if(flag){
                        c = -c;
                    }
                    s.push(c);
                }
            }
            return (s.top());
        }
        
    
};
