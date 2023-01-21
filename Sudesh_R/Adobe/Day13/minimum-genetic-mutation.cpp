//https://leetcode.com/problems/minimum-genetic-mutation/description/

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int result = 0;
        unordered_set<string> pool, visited;
        vector<char> choices = {'A', 'C', 'G', 'T'};

        for (string s : bank) pool.insert(s);

        if (pool.count(end) == 0) return -1;

        queue<string> geneQueue;
        geneQueue.push(start), visited.insert(start);

        while (!geneQueue.empty()) {
            int size = geneQueue.size();

            for (int i = 0; i < size; i++) {
                string current = geneQueue.front();
                geneQueue.pop();

                for (int j = 0; j < current.size(); j++) {
                    for (int k = 0; k < 4; k++) {
                        string next = current;
                        next[j] = choices[k];

                        if (!visited.count(next) && pool.count(next)) {
                            visited.insert(next), geneQueue.push(next);
                            if (next == end) return result + 1;
                        }
                    }
                }
            }
            result ++;
        }
        return -1;
    }
};
