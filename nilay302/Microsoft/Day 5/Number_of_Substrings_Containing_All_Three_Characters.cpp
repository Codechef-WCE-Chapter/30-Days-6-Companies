class Solution {
public:
    int numberOfSubstrings(string s) {
        int i = 0;
        int j = 0;
        vector<int>a(3,0);
        int ans = 0;
        for(j = 0;j<s.size();j++){
            a[s[j]-'a']++;
            // cout<<a[s[j]-'a']<<" ";
            while(a[0]>0 && a[1]>0 && a[2]>0 && i<=j){
                cout<<"entered"<<" "; 
                ans+=s.size()-j;
                a[s[i]-'a']--;
                i++;
            }
        }
        return ans;
        
    }
};