#include <iostream>
#include <vector>

using namespace std;
void generateCombinations(int k, int n, vector<int> &combination, vector<vector<int>> &combinations)
{
    // If the current combination has reached the desired length and sum, add it to the list of combinations.
    if (k == 0 && n == 0)
    {
        combinations.push_back(combination);
        return;
    }
    // If the current combination exceeds the desired sum, discard it.
    if (k <= 0 || n <= 0)
    {
        return;
    }
    // Try adding the next smallest number (i) to the current combination and generate all the combinations that can be formed.
    for (int i = 1; i <= 9; i++)
    {
        if (combination.empty() || combination.back() < i)
        {
            combination.push_back(i);
            generateCombinations(k - 1, n - i, combination, combinations);
            combination.pop_back();
        }
    }
}

int main()
{
    int k, n;
    cin >> k >> n;
    vector<int> combination;
    vector<vector<int>> combinations;
    generateCombinations(k, n, combination, combinations);
    // Print the generated combinations.
    for (const auto &c : combinations)
    {
        for (int i : c)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
