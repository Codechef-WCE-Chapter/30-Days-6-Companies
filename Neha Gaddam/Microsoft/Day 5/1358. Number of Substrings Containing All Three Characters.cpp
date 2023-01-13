class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>count(3,0);
        int cnt=0,j=0;
        for(int i=0;i<s.length();i++)
        {
            count[s[i]-'a']++;
            while(count[0] and count[1] and count[2])
            {
                --count[s[j]-'a'];
                j++;
            }
            cnt+=j;
        }
        return cnt;
    }
};