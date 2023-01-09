Problem : https://leetcode.com/problems/bulls-and-cows/

Solution : 

class Solution {
public:
    string getHint(string s, string g) {
        int x = 0, y = 0;
        map<char, int> f1;
        map<char, int> f2;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == g[i]) {
                x++;
            }
            else {
                f1[s[i]]++;
                f2[g[i]]++;
            }
        }

        for(auto &i : f2){
            if(f1.find(i.first) != f1.end()){
                y += min(i.second, f1[i.first]);
            }
        }

        return to_string(x)+'A'+to_string(y)+'B';
    }
};