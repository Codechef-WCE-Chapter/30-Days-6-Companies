
// https: // leetcode.com/problems/evaluate-reverse-polish-notation/description/

// Input: tokens = ["2","1","+","3","*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9

// Algo
//  1) if operator then pop 2 elements of stack and perform operation
//  2) else push in stack
//  3) return st.top()

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

const int M = 1e9 + 7;

class Solution
{
public:
    int evalRPN(vector<string> &v)
    {

        int n = v.size();
        int sum = 0;
        stack<long long int> st;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == "+" || v[i] == "-" || v[i] == "*" || v[i] == "/")
            {

                long long int first = st.top();
                st.pop();
                long long int second = st.top();
                st.pop();

                if (v[i] == "+")
                {
                    first = first + second;
                }
                if (v[i] == "-")
                {
                    first = second - first;
                }
                if (v[i] == "*")
                {
                    first = first * second;
                }

                if (v[i] == "/")
                {
                    first = second / first;
                }
                st.push(first);
            }
            else
            {
                st.push(stoll(v[i]));
            }
        }

        return st.top();
    }
};

int32_t main()
{

    return 0;
}