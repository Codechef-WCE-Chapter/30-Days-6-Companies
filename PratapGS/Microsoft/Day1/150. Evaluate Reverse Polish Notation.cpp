/*

class Solution {
public:
     int evalRPN(vector<string>& tokens) {
        stack<int> res;

        for(auto x : tokens) {
            
            if(isdigit(x.back())) res.push(stoi(x)); 
            else {
                long long int n2 = res.top(); 
                res.pop();
                long long int n1 =res.top(); 
                res.pop();  
                if(x == "+") res.push(n1 + n2);
                else if (x == "-") res.push(n1 - n2);
                else if (x == "*") res.push(n1 * n2);
                else res.push(n1 / n2); 
            }
        }
        return res.top();

        


        
    }
};

*/
