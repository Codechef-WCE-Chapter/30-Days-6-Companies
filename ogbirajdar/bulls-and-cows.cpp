#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        
        unordered_map<char,int> m1,m2;
        for(auto i: secret)
        {
            m1[i]++;
        }
        for(auto i: guess)
        {
            m2[i]++;
        }
        
        int x=0, y=0;
        for(int i=0; i<secret.size(); i++)
        {
            if(secret[i]==guess[i])
            {
                x++;
                auto it = m1.find(secret[i]);
                if(it!=m1.end())
                {
                    if(--it->second==0)
                        m1.erase(it);
                }
                
                auto ij = m2.find(guess[i]);
                if(ij!=m2.end())
                {
                    if(--ij->second==0)
                        m2.erase(ij);
                }
            }
        }
        
        for(auto i: m1)
        {
            if(m2.find(i.first)!=m2.end())
            {
                y += min(i.second, m2[i.first]);
            }
        }
        
        string ans="";
        ans += to_string(x) + 'A' + to_string(y) + 'B';
        return ans;
        
    }
};