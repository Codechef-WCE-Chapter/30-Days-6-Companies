class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        
        int n = students.size();
        
        vector<int> next(n, 0);
        for(int i = 0; i < n; i++) next[i] = i;
        
        int ans = 0;
        do {
            
            int curr = 0;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < students[0].size(); j++) {
                    if(students[next[i]][j] == mentors[i][j]) curr++;
                }
            }
            
            ans = max(ans, curr);
            
        } while (next_permutation(next.begin(), next.end()));
        
        return ans;
    }
};
