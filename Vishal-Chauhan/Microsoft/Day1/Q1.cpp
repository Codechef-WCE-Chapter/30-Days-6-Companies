#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int evaluateRPN(const vector<string> &tokens)
{
    stack<int> operands;
    for (const string &token : tokens)
    {
        if (token == "+")
        {
            // Pop the top two operands, add them, and push the result.
            int op2 = operands.top();
            operands.pop();
            int op1 = operands.top();
            operands.pop();
            operands.push(op1 + op2);
        }
        else if (token == "-")
        {
            // Pop the top two operands, subtract the second one from the first, and push the result.
            int op2 = operands.top();
            operands.pop();
            int op1 = operands.top();
            operands.pop();
            operands.push(op1 - op2);
        }
        else if (token == "*")
        {
            // Pop the top two operands, multiply them, and push the result.
            int op2 = operands.top();
            operands.pop();
            int op1 = operands.top();
            operands.pop();
            operands.push(op1 * op2);
        }
        else if (token == "/")
        {
            // Pop the top two operands, divide the first one by the second, and push the result.
            int op2 = operands.top();
            operands.pop();
            int op1 = operands.top();
            operands.pop();
            operands.push(op1 / op2);
        }
        else
        {
            // Token is an operand, so push it onto the stack.
            operands.push(stoi(token));
        }
    }
    // The result will be the top element of the stack.
    return operands.top();
}

int main()
{

    tokens = {"2", "1", "+", "3", "*"};
    cout << evaluateRPN(tokens) << endl; // prints "9"

    tokens = {"4", "13", "5", "/", "+"};
    cout << evaluateRPN(tokens) << endl; // prints "6"
}