//_________________________________________________________//
#include <bits/stdc++.h>
#define pajju             main
#define Prajwal           ios_base::sync_with_stdio(false);
#define Shah              cin.tie(NULL);
#define ll                long long
#define vl                vector<long long>
#define vi                vector<int>
#define vp                vector<pair<long long , long long>>
#define pb                push_back
#define mp                make_pair
#define mid(l, h)         ((l+h)/2)
#define f_ab(i, a, b)     for (auto i = a; i < b; ++i)
#define f_rab(i, a, b)    for (auto i = a; i >= b; --i)
#define mod               1'000'000'007
#define endl              '\n'
#define ff                first
#define ss                second
#define pinf              LLONG_MAX
#define ninf              LLONG_MIN
//_______________________________________________________//

using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>st;
        for(int i = 0; i < tokens.size(); ++i){
            if(tokens[i] == "+"){
                string c1 = st.top();
                st.pop();
                string c2 = st.top();
                st.pop();
                int x = stoi(c1);
                int y = stoi(c2);
                st.push(to_string(x+y));
            }
            else if(tokens[i] == "-"){
                string c1 = st.top();
                st.pop();
                string c2 = st.top();
                st.pop();
                int x = stoi(c1);
                int y = stoi(c2);
                st.push(to_string(y-x));
            }
            else if(tokens[i] == "/"){
                string c1 = st.top();
                st.pop();
                string c2 = st.top();
                st.pop();
                int x = stoi(c1);
                int y = stoi(c2);
                st.push(to_string(y/x));
            }
            else if(tokens[i] == "*"){
                string c1 = st.top();
                st.pop();
                string c2 = st.top();
                st.pop();
                long long int x = stol(c1);
                long long int y = stol(c2);
                st.push(to_string(x*y));
            }
            else{
                st.push(tokens[i]);
            }
        }
        string x = st.top();
        return stoi(x);
    }
};
