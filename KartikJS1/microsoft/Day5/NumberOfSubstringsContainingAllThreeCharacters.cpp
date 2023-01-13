class Solution {
public:
    int numberOfSubstrings(string s) {
        int a = -1;
        int b = -1;
        int c = -1;
        int ans = 0;
        for(int i = 0; i<s.size(); i++)
        {
            if(s[i] == 'a')
            {
                a = i;
            }
            if(s[i] == 'b')
            {
                b = i;
            }
            if(s[i] == 'c')
            {
                c = i;
            }
            if(i > 1)
            {
                ans += min(a,min(b,c)) + 1;
            }

        }
        return ans;

        
    }
};
