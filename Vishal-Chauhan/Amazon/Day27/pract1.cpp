#include <iostream>
using namespace std;
class Solution
{
public:
    // 1.recurssive
    // int cal(string s1,string s2,int l1,int l2,vector<vector<int>> dp){
    //         // cout<<"l1:"<<l1<<"  l2:"<<l2<<endl;
    //     if(l1<0 || l2<0){
    //         return 0;
    //     }
    //     else if(dp[l1+1][l2+1]>0)return dp[l1+1][l2+1];
    //     else if(s1[l1]==s2[l2]){
    //         // cout<<"gotted:"<<s1[l1]<<endl;
    //         return 1+cal(s1,s2,l1-1,l2-1,dp);
    //
    //     }
    //     else{
    //         return max(cal(s1,s2,l1,l2-1,dp),cal(s1,s2,l1-1,l2,dp));
    //
    //     }
    // }

    // 2.memorisation
    // int cal(string s1,string s2,int l1,int l2,vector<vector<int>> dp){
    //         // cout<<"l1:"<<l1<<"  l2:"<<l2<<endl;
    //     if(l1<0 || l2<0){
    //         return 0;
    //     }
    //     else if(dp[l1+1][l2+1]>0)return dp[l1+1][l2+1];
    //     else if(s1[l1]==s2[l2]){
    //         // cout<<"gotted:"<<s1[l1]<<endl;
    //         dp[l1+1][l2+1] =1+cal(s1,s2,l1-1,l2-1,dp);
    //         return dp[l1+1][l2+1] ;
    //     }
    //     else{
    //         dp[l1+1][l2+1] = max(cal(s1,s2,l1,l2-1,dp),cal(s1,s2,l1-1,l2,dp));
    //         return dp[l1+1][l2+1] ;
    //     }
    // }

    // 3.tabulirasation DP
    int cal(string s1, string s2, int l1, int l2, vector<vector<int>> dp)
    {
        int rl = l1, cl = l2;

        for (int i = 0; i <= rl; i++)
        {
            for (int j = 0; j <= cl; j++)
            {
                if (i == 0)
                {
                    dp[i][j] = 0;
                }
                else if (j == 0)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    if (s1[i - 1] == s2[j - 1])
                    {
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    }
                    else
                    {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
        }
        return dp[rl][cl];
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int l1 = text1.length(), l2 = text2.length();
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
        return cal(text1, text2, l1, l2, dp);
    }
};