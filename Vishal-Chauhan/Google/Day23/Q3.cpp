#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxCoins(vector<int> &piles)
    {

        sort(piles.begin(), piles.end());

        int k = piles.size() / 3; // k is the no. of times you will pick a pile

        int sum = 0; // store the  no. of coins you will pick

        int i = piles.size() - 2; // i is a pointer to the piles that you will pick

        while (k--)
        {
            sum += piles[i];
            i -= 2;
        }
        return sum;
    }
};

int main()
{
    Solution s;
    vector<int> piles{3, 9, 4, 6, 7};
    cout << "ans:" << s.maxCoins(piles) << endl;
}