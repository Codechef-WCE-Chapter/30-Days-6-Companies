// Reverse Polish Notation:-
// Stack based operations. Draw stack & then solve with LIFO.
// Steps:
// if (operator == found)
// 	pop first two operands and perform operation
// else
// 	add operands in stack

// Time complexity:
// O(N) --> N is the size of the array

// Space complexity:
// O(N) ---> stack size

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> s;
        for(string x:tokens){
            if(x == "+"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b+a);
            }
            else if(x == "-"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b-a);
            }
            else if(x == "*"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b*a);
            }
            else if(x == "/"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b/a);
            }
            else{
                s.push(stoi(x));
            }
        }
        return s.top();
    }
};