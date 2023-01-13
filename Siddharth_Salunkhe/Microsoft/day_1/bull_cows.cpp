class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> st;
        int present=0;
        for(int i=0;i<secret.size();i++) st[secret[i]]++;
        for(int i=0;i<guess.size();i++){
            
            if(st[guess[i]]>0){
                present++;
                st[guess[i]]--;
            }else{
                continue;
            }
        }
        int bull=0;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]) bull++;
        }
        present=present-bull;
        string ans="";
        ans.append(to_string(bull));
        ans.append("A");
        ans.append(to_string(present));
        ans.append("B");
        return ans;
    }
};
