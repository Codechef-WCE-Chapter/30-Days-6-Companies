class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();
        int b = 0, c = 0;
        int freq1[10] = {0};
        int freq2[10] = {0};
        for(int i = 0; i<n; i++)
        {
            if(secret[i] == guess[i])
            {
                b++;
            }
            else
            {
                freq1[secret[i] - '0']++;
                freq2[guess[i] - '0']++;
            }
        }
        for(int i = 0; i<10; i++)
        {
            c += min(freq1[i],freq2[i]);
        }
        string ans = "";
        ans+=to_string(b);
        ans+='A';
        ans+=to_string(c);
        ans+='B';
        return ans;
    }
};