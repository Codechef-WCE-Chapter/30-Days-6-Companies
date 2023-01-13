class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0,j=0;
        int end=s.size();
        int cnt=0;
        map<char,int>mp;
        while(j<end)
        {
                mp[s[j]]++;
            if(mp.size()<3)
            {
                j++;
            }
            else if(mp.size()==3)
            {
                while(mp.size()==3)
                {
                    cnt+=end-j;
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                        mp.erase(s[i]);
                   i++;
                }
                j++;
            }
        }
        return cnt;
    }
};