//https://leetcode.com/problems/bulls-and-cows/solutions/3025920/0ms-easy-approach/


class Solution {
public:
    string getHint(string s, string g) {
        int gus[10]={0},sec[10]={0};
        int A=0,B=0;

        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=g[i])
            {
                sec[int(s[i])-48]++;
                gus[int(g[i])-48]++;
            }
            else
             A++;
        }
        for(int i=0;i<10;i++)
        {
            B+=min(sec[i],gus[i]);
        }
        return to_string (A)+"A"+to_string (B)+"B";
        
    }
};