class Solution {
public:
    string longestPrefix(string s) {
        unordered_set<string>mp;
        int j=s.size()-1;
        long start=0,end=0,mul=1,mod=1e9+7;
        long len=0;
        for(int i=0;i<s.length()-1 and j>0;i++,j--)
        {
            int f=s[i]-'a',l=s[j]-'a';
            start=(start*26+f)%mod;
            end=(l*mul+end)%mod;
            mul=(mul*26)%mod;
            if(start==end)
                len=i+1;
        }
    
        return s.substr(0,len);
    }
};