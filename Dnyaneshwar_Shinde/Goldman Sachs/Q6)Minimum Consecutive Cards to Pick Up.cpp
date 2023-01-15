// https: // leetcode.com/problems/minimum-consecutive-cards-to-pick-up/description/

// You are given an integer array cards where cards[i] represents the value of the ith card. A pair of cards are matching if the cards have the same value

// Return the minimum number of consecutive cards you have to pick up to have a pair of matching cards among the picked cards.If it is impossible to have matching cards, return -1.

// Input: cards = [3,4,2,3,4,7]
// Output: 4
// Explanation: We can pick up the cards [3,4,2,3] which contain a matching pair of cards with value 3. Note that picking up the cards [4,2,3,4] is also optimal.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumCardPickup(vector<int> &v)
    {

        int n = v.size();
        int ans = INT_MAX;
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            mp[v[i]].push_back(i);
        }

        for (auto i : mp)
        {

            vector<int> curr = i.second;
            for (int j = 0; j < curr.size() - 1; j++)
            {

                int dist = abs(curr[j] - curr[j + 1]);
                ans = min(ans, dist);
            }
        }

        if (ans == INT_MAX)
            return -1;

        return ans + 1;
    }
};

int32_t main()
{

    return 0;
}