class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> V(3, 0);
        int n = s.size(), count = 0;

        for(int i=0, j=0; j<n; j++){
            V[s[j] - 'a']++;

            while(V[0]>0 && V[1]>0 && V[2]>0){
                count += (n - j);
                V[s[i] - 'a']--;
                i++;
            }
        }

        return count;
    }
};
