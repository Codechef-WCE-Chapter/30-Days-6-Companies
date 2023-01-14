#include<bits/stdc++.h>
using namespace std;
    class Solution {
    public:
        string getHint(string secret, string guess) {
            map<char,int> counter;
            int bull=0,cow=0;
            for(int i=0;i<secret.size();i++)
            {
                if(secret[i]==guess[i])
                {
                    bull++;
                }
                else
                {
                    counter[secret[i]]++;
                }
            }
            for(int i=0;i<guess.size();i++)
            {
                if(secret[i]!=guess[i]&&counter[guess[i]]>0)
                {
                    cow++;
                    counter[guess[i]]--;
                }
            }
            string ans="";
            ans+=to_string(bull)+'A'+to_string(cow)+'B';
            return ans;
        }
};