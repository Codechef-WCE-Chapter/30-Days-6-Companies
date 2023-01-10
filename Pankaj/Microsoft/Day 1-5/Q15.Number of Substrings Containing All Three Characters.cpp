//Microsoft: Q15. Number of Substrings Containing All Three Characters
class Solution {
public:
    static bool isValid(int freq[]){
        return (freq[0]>0)&&(freq[1]>0)&&(freq[2]>0);
    }
    int numberOfSubstrings(string s) {
        int n=s.size();
        int freq[4]={0};
        int i=0;
        int ans=0;
        for(int j=0;j<n;j++){
            freq[s[j]-'a']++;
            while(isValid(freq)){
                ans+=(n-j);
                freq[s[i]-'a']--;
                i++;
            }
        }
        return ans;
    }
};