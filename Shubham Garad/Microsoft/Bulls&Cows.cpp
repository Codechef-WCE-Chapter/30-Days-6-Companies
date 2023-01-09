class Solution {
public:
    string getHint(string secret, string guess) {
        
        int bulls = 0 , cow = 0;

        unordered_map<char,int>mp1 , mp2;

        for(int i = 0 ;i< secret.size();++i)
        {
            if(secret[i]==guess[i])
            {
                bulls++;
            }
            else
            {
                mp1[secret[i]]++;
                mp2[guess[i]]++;
            }
        }
        for(auto it : mp1)
        {
            if(mp2.find(it.first) != mp2.end())
            {
                cow += min(it.second , mp2[it.first]);
            }
        }
        string ans = to_string(bulls)+"A"+to_string(cow)+"B";
        return ans;
    }
};