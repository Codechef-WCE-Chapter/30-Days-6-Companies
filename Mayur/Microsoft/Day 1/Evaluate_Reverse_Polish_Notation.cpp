//https://leetcode.com/problems/evaluate-reverse-polish-notation/submissions/875341404/



class Solution {
public:
    int evalRPN(vector<string>& t) {
        // int res;
        stack<int>s;
        // int a=int(t[0])-48;
        // cout<<t[0];
        // s.push(a);

       
            for(string x:t)
            {
                if(x=="*")
                {
                    int a=s.top();
                    s.pop();
                    int b=s.top();
                    s.pop();
                    int c=a*b;
                    s.push(c);
                }
                else if(x=="+")
                {
                    int a=s.top();
                    s.pop();
                    int b=s.top();
                    s.pop();
                    int c=a+b;
                    s.push(c);
                }
                else if(x=="-")
                {
                    int a=s.top();
                    s.pop();
                    int b=s.top();
                    s.pop();
                    int c=b-a;
                    s.push(c);
                }
                else if(x=="/")
                {
                    int a=s.top();
                    s.pop();
                    int b=s.top();
                    s.pop();
                    int c=b/a;
                    s.push(c);
                }
                else
                {
                    s.push(stoi(x));
                }
            }
        return s.top();
    }
};
