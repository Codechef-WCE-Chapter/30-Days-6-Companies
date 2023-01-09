//299.Bulls and Cows

class Solution {
public:
    string getHint(string secret, string guess) {
    
        unordered_map<char,int> mp;
        unordered_map<int,bool> mark;
        int bull=0,cow=0;
        
        for(auto &e :secret)
            mp[e]++;
        
        for(int i=0;i<secret.size();++i)
        {
            if(secret[i]==guess[i])
            {
                bull++;
                mp[secret[i]]--;  
            }
            else
                mark[i]=1;
        }
        
        for(int i=0;i<guess.size();++i)
        {
            if(mark[i] && mp[guess[i]]>0)
            {
                cow++;
                mp[guess[i]]--;
            }
        }
        
        string ans=to_string(bull)+"A"+to_string(cow)+"B";
        return ans;
    }
};
