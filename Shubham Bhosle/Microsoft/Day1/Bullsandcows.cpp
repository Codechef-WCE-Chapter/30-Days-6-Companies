class Solution {
public:
    string getHint(string s, string g) {
        string ans = "";
        int n = s.size();
        int bulls=0,cows=0;
       
        map<char,int> mp1;
        for(int i=0; i<n; i++){
            mp1[s[i]]++;
        }       

        for(int i=0; i<n; i++){
            if(s[i] == g[i]){
                bulls++;
                mp1[s[i]]--;
            }
        }

        for(int i=0; i<n; i++){
            if(s[i] != g[i] && mp1[g[i]] > 0){
                cows++;
                mp1[g[i]]--;                
            }
        }

        ans =to_string(bulls) + "A" +to_string(cows) +"B";
        return ans;
    }    
};
