class Solution
{
public:
    bool canFinish(int n, vector<vector<int>> &p)
    {
        queue<int> q;
        vector<int> degree(n, 0);           // Degree count
        unordered_map<int, vector<int>> mp; // Edges mapping
        for (auto it : p)
        {
            mp[it[1]].emplace_back(it[0]); // If you want to learn skill at index 0 you need to learn skill 1
            // so by learning skill 1, what skills are next that you can learn is given in the children of 1, i.e. mp[1] ={ skills that i can learn }
            degree[it[0]]++; // number of skill required to learn skill at index 0
        }
        // [4,2],[4,3],[2,1]
        // q = [4]
        // q = [4]
        // q = [4]
        // q = [4]
        for (int i = 0; i < n; i++)
            if (!degree[i])
                q.push(i); // skills that dont have any prerequisite
        while (!q.empty())
        {
            int x = q.size();
            while (x--)
            {
                int curr = q.front();
                q.pop();
                n--;
                for (auto it : mp[curr])
                {
                    if (--degree[it] == 0)
                    { // remove indegree of the child because we just learnt the parent "curr" :)
                        // at any moment if the child becomes zero that means we have aced all the skills required to learn the child, so we can now better leanr from kid
                        q.push(it);
                    }
                }
            }
        }

        return n == 0; // all skills are aced ::()::
    }
};