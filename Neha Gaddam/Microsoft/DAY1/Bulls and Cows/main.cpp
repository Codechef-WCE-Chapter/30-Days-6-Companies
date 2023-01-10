class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int>v(10,0);
        for(int i=0;i<secret.size();i++)
            v[secret[i]-'0']++;
        int bull=0,cow=0;
        for(int i=0;i<guess.size();i++)
        {
            if(guess[i]==secret[i])
            {
                bull++;
                v[guess[i]-'0']--;
            }
            
        }
        for(int i=0;i<guess.size();i++)
        {
            if(guess[i]!=secret[i] and v[guess[i]-'0'])
            {
                cow++;
                v[guess[i]-'0']--;
            }
            
        }
        // string s;
        string s=to_string(bull)+"A"+to_string(cow)+"B";
        return s;
    }
};