// https: // leetcode.com/problems/bulls-and-cows/

// Input: secret = "1807", guess = "7810"
// Output: "1A3B"
// Explanation: Bulls are connected with a '|' and cows are underlined:
// "1807"
//   |
// "7810"

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string getHint(string secret, string guess)
    {

        int cow = 0, bull = 0;
        vector<int> s(10, 0), g(10, 0);
        for (int i = 0; i < secret.length(); i++)
        {
            if (secret[i] == guess[i])
            {
                cow++;
            }
            else
            {
                s[secret[i] - '0']++;
                g[guess[i] - '0']++;
            }
        }

        for (int i = 0; i < 10; i++)
        {
            //   cout<<s[i]<<" "<<g[i]<<endl;
            bull += min(s[i], g[i]);
        }

        //  cout<<cow<<" "<<bull<<endl;
        return to_string(cow) + 'A' + to_string(bull) + 'B';
    }
};

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}