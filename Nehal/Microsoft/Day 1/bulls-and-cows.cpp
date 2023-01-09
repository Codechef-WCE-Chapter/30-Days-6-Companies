class Solution
{
public:
    string getHint(string s, string g)
    {
        int a = 0, b = 0;
        int n = s.size();
        map<char, int> mp1;
        map<char, int> mp2;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == g[i])
            {
                a++;
            }
            else
            {
                mp1[s[i]]++;
                mp2[g[i]]++;
            }
        }
        for (auto [c, f] : mp2)
        {
            if (mp1.find(c) != mp1.end())
            {
                b += min(f, mp1[c]);
            }
        }
        return to_string(a) + "A" + to_string(b) + "B";
    }
};