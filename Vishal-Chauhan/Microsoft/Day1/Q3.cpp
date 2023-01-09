#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string getHint(const string &secret, const string &guess)
{
    // Count the number of bulls count (bc) and cows count (cc).
    int bc = 0, cc = 0;
    unordered_map<char, int> counts;
    for (int i = 0; i < secret.length(); ++i)
    {
        // If the guess is correct, it's a bull.
        if (secret[i] == guess[i])
        {
            ++bc;
        }
        // Otherwise, increment the count of the digit in the secret.
        // We will later use this count to determine how many  cc there are.
        else
        {
            ++counts[secret[i]];
        }
    }
    // Check each digit in the guess to see if it is a cow.
    for (int i = 0; i < guess.length(); ++i)
    {
        // If the guess is incorrect and the digit has appeared in the secret, it's a cow.
        if (secret[i] != guess[i] && counts[guess[i]] > 0)
        {
            ++cc;
            --counts[guess[i]];
        }
    }
    // Return the hint in the requested format.
    return to_string(bc) + 'A' + to_string(cc) + 'B';
}
int main()
{
    string secret = "1807", guess = "7810";
    cout << getHint(secret, guess) << endl;

    secret = "1123", guess = "0111";
    cout << getHint(secret, guess) << endl;
}