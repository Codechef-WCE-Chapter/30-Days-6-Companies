// https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int val;
        int a,b,c;
        for(int i= 0;i<tokens.size();i++){
            
            
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                if(!s.empty()){
                    b = s.top();
                    s.pop();
                    if(s.empty()){
                        s.push(0);
                        break;
                    } 
                    a = s.top();
                    s.pop();
                    if(tokens[i]=="+"){
                        c = a+ b;
                    }
                    else if(tokens[i]=="-"){
                        c = a-b;
                    }
                    else if(tokens[i]=="*") c = a*b;
                    else if(tokens[i]=="/"){
                        if(b) c = a/b;
                    } 
                    s.push(c);

                }
                

            }else{
                
                    val = stoi(tokens[i]);
                s.push(val);
            
            }
        }
        return s.top();
    }
};
