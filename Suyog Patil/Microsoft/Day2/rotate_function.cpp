
class Solution
{
public:
    int maxRotateFunction(vector<int> &v)
    {
        int n = v.size();
        int ans = 0;
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += v[i];
            ans += v[i] * i;
        }

        int j = n - 1;
        int prevAns = ans;
        while (j > 0)
        {
            int temp = prevAns - (n * v[j]) + sum;
            prevAns = temp;
            ans = max(ans, temp);
            j--;
        }

        return ans;
    }
};
