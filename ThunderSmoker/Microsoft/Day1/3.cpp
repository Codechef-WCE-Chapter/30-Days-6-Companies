// Bulls and Cows
class Solution
{
public:
    string getHint(string secret, string guess)
    {
        map<int, int> m1;
        for (int i = 0; i < secret.size(); i++)
        {
            m1[secret[i]]++;
        }

        int bulls = 0, cows = 0;
        for (int i = 0; i < secret.size(); i++)
        {
            if (secret[i] == guess[i])
            {
                if (m1[secret[i]] > 0)
                {
                    bulls++;
                    m1[secret[i]]--;
                }
            }
        }
        for (int i = 0; i < secret.size(); i++)
        {
            if (guess[i] != secret[i])
            {
                if (m1[guess[i]] > 0)
                {
                    cows++;
                    m1[guess[i]]--;
                }
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};