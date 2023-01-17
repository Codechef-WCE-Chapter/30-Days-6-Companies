/*
https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/
*/

#include<bits/stdc++.h>
using namespace std;

/* 
Approach:
T.C : O(n)
S.C : O(n) -> threshold 
- Step1: Traverse through each index and find the indices of a, b , c resp appearing before this curr index
- Step2: Store the max index out of ai, bi, ci at corres curr index in a new arr threshold
- Step3: Traverse through threshold -> for each index incr count with (n - threshold[i] (max_index needed)) -> return count

*/
class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int n = s.length(), count=0, arr[n] ;
        string substr;
        int ai=n, bi=n, ci=n, max_index=0;
        for(int i=n-1; i>=0; i--)
        {
           if(s[i]=='a')
           ai = i;
           else if(s[i]=='b')
           bi = i;
           else if(s[i]=='c')
           ci = i;
           max_index = max(ai, max(bi, ci));
           arr[i] = max_index;
        }
        for(int i=0; i<n; i++)
        {
            count+= (n-arr[i]);
        }
        
        return count;
    }
};