// https://leetcode.com/problems/bulls-and-cows/description/
class Solution {
public:
    string getHint(string s, string g) {
        int b = 0;
        int c = 0;
        map<char , int>m;
        for(auto it : s){m[it]++;}
        for(int i = 0;i<g.size();i++){
            if(g[i] == s[i] && m[s[i]] >0){
                m[s[i]]--;
                b++;
            }
           
        }
         for(int i = 0;i<g.size();i++){
             if( g[i] != s[i] && m[g[i]] > 0){
                c++;
                m[g[i]]--;
            }
           
        }

        return to_string(b) + "A" + to_string(c) +"B";
    }
};
