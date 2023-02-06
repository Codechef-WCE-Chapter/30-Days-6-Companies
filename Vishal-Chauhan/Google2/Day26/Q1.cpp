#include <vector>
#include <random>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
private:
    vector<int> original;
    mt19937 rng;

public:
    Solution(vector<int> &nums) : original(nums), rng(random_device()()) {}

    vector<int> reset()
    {
        return original;
    }

    vector<int> shuffle()
    {
        vector<int> shuffled(original);
        for (int i = 0; i < shuffled.size(); i++)
        {
            uniform_int_distribution<int> dist(i, shuffled.size() - 1);
            int j = dist(rng);
            swap(shuffled[i], shuffled[j]);
        }
        return shuffled;
    }
};

int main()
{
    Solution s;
}