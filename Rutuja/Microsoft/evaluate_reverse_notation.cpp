class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>stk;
       
        for( auto &a:tokens){
            if(a!="+"&&a!="-"&&a!="*"&&a!="/"){
            stk.push(stoi(a));
            }
            else{
                int n1=stk.top();
                stk.pop();
                int n2=stk.top();
                stk.pop();
                if(a=="+"){
                   stk.push(n2+n1) ;
                }
                else if(a=="-"){
                    stk.push(n2-n1);
                }
                else if(a=="*"){
                    stk.push(n2*n1);
                }
                else{
                    stk.push(n2/n1);
                }
            }
        }
        return stk.top() ;
        
    }
};
