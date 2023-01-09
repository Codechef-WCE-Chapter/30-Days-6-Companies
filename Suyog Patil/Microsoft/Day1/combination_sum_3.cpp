class Solution
{
public:
    string getHint(string secret, string guess)
    {
        map<char, int> secretM, guessM;

        int bulls = 0, cows = 0;

        for (int i = 0; i < secret.size(); i++)
        {
            if (secret[i] == guess[i])
                bulls++;
            else
            {
                secretM[secret[i]]++;
                guessM[guess[i]]++;
            }
        }

        for (auto x : secretM)
            if (guessM.find(x.first) != guessM.end())
                cows += min(x.second, guessM[x.first]);

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
