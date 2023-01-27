bool sortbyCond(const pair<int, string> &a,
                const pair<int, string> &b)
{
    if (a.first != b.first)
        return (a.first > b.first);
    else
        return (a.second < b.second);
}
class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        sort(words.begin(), words.end());
        int cnt = 0;
        vector<pair<int, string>> v;
        for (int i = 0; i < words.size() - 1; i++)
        {
            if (words[i] != words[i + 1])
            {
                v.push_back({cnt + 1, words[i]});
                cnt = 0;
            }
            else
            {
                cnt++;
            }
        }
        v.push_back({cnt + 1, words[words.size() - 1]});
        sort(v.begin(), v.end(), sortbyCond);
        vector<string> ans;
        int i = 0;
        while (k--)
        {
            ans.push_back(v[i].second);
            i++;
        }
        return ans;
    }
};
