class Solution {
public:
    string getHint(string secret, string guess) {
        map<char,int> mp;
        int n=secret.size();
        int b=0,c=0;
        for(int i=0;i<n;i++)
        {
            if(secret[i]==guess[i])
                b++;
            else
                mp[secret[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(secret[i]!=guess[i] && mp.find(guess[i])!=mp.end())
            {
                c++;
                mp[guess[i]]--;
                if(mp[guess[i]]==0)
                    mp.erase(guess[i]);
            }
        }
        string ans=to_string(b)+"A"+to_string(c)+"B";
        return ans;
        
    }
};
