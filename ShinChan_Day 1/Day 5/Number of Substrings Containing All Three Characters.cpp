class Solution {
public:
    int numberOfSubstrings(string s) {
       int i=0, j=0, end=s.size()-1, count=0, n=s.size();
        map<char, int> mp;

       while(j<n){
           mp[s[j]]++;

           while(mp['a']>=1 && mp['b']>=1 && mp['c']>=1){
               count+=1+ (end-j);
               mp[s[i]]--;
               i++;
           }
           j++;
       }
       return count;
    }
};
