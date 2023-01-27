bool isprime(int n)
{
    int i = 2;
    while (i <= sqrt(n))
    {
        if (n % i == 0)
            return false;
        i++;
    }
    return true;
}
class Solution
{
public:
    vector<int> closestPrimes(int left, int right)
    {
        int temp = -1;
        int diff = INT_MAX;
        int x = -1, y = -1;
        if (left == 1)
            left++;
        for (int i = left; i <= right; i++)
        {
            if (isprime(i))
            {
                if (temp == -1)
                    temp = i;
                else
                {
                    if (diff > i - temp)
                    {
                        x = temp;
                        y = i;
                        diff = i - temp;
                    }
                    temp = i;
                }
            }
        }
        vector<int> v = {x, y};
        return v;
    }
};
