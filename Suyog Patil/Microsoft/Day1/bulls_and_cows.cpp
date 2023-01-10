class Solution
{
public:
    string getHint(string secret, string guess)
    {
        map<char, int> sM, gM;

        int bulls = 0, cows = 0;

        for (int i = 0; i < secret.size(); i++)
        {
            if (secret[i] == guess[i])
                bulls++;
            else
            {
                sM[secret[i]]++;
                gM[guess[i]]++;
            }
        }

        for (auto x : sM)
            if (gM.find(x.first) != gM.end())
                cows += min(x.second, gM[x.first]);

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
