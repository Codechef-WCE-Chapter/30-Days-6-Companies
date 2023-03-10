* Problem : https://leetcode.com/problems/evaluate-reverse-polish-notation/

* Solution : 

#define ll long long
class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<string> s;
        for(int i = 0; i < t.size(); ++i){
            if(t[i] == "+"){
                ll x = stol(s.top()); s.pop();
                ll y = stol(s.top()); s.pop();
                s.push(to_string(y + x));
            }else
            if(t[i] == "-"){
                ll x = stol(s.top()); s.pop();
                ll y = stol(s.top()); s.pop();
                s.push(to_string(y - x));
            }else
            if(t[i] == "*"){
                ll x = stol(s.top()); s.pop();
                ll y = stol(s.top()); s.pop();
                s.push(to_string(y * x));
            }else
            if(t[i] == "/"){
                ll x = stol(s.top()); s.pop();
                ll y = stol(s.top()); s.pop();
                s.push(to_string(y / x));
            }else
                s.push(t[i]);
        }

        return stol(s.top());
    }
};