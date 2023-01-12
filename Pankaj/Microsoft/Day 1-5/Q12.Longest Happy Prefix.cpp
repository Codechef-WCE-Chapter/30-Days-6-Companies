//In order to understand this solution read this article on KMP algorithm
//https://www.interviewbit.com/blog/kmp-algorithm-pattern-search/
class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size();
        vector<int> lps(n,0);//longest prefix suffix
        //lps[i] denotes longest prefix suffix till index i
        int i=1,len=0;
        while(i<n){
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len>0){
                    len=lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        return s.substr(0,lps[n-1]);
    }
};