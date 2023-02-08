
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class TweetCounts
{
    map<string, map<int, int>> tweets;
    int frequency[3] = {60, 3600, 86400};

public:
    TweetCounts()
    {
    }

    void recordTweet(string tweetName, int time)
    {
        tweets[tweetName][time]++;
    }

    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime)
    {
        int f;
        if (freq == "minute")
            f = 0;
        else if (freq == "hour")
            f = 1;
        else
            f = 2;
        vector<int> ans;
        for (int i = startTime; i <= endTime; i += frequency[f])
        {
            int j = min(i + frequency[f] - 1, endTime);
            int cnt = 0;
            for (auto it = tweets[tweetName].lower_bound(i); it != tweets[tweetName].end() && it->first <= j; it++)
            {
                cnt += it->second;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */

int main()
{
}