class Solution {
public:

long solve(char op, int i1,int i2){
    if(op=='+')return i1+i2;
    else if(op=='-')return i1-i2;
    else if(op=='*')return i1*i2;
    else return i1/i2;
}
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i].size()==1&& tokens[i][0]<48){
                long i2=s.top();
                s.pop();
                long i1=s.top();
                s.pop();
                string op= tokens[i];
                long ans=solve(op[0],i1,i2);
                s.push(ans);
            }
            else{
                s.push(stol(tokens[i]));
            }
        }
        return s.top();
    }
};