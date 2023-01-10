class Solution {
public:
    string getHint(string secret, string guess) {
        string ans;
        map<char,int> ct1;
        for(int i=0;i<guess.size();i++) ct1[guess[i]]++;

        int count=0,find=0;
        for(int i=0;i<guess.size();i++)
        {
            if(secret[i]==guess[i]) 
            count++;
            size_t found = guess.find(secret[i]);
            if (found != string::npos)
            {
               if(ct1[secret[i]]){
               find++;
               ct1[secret[i]]--; 
               } 
            }
            
        }
        ans=ans+to_string(count)+'A'+to_string(find-count)+'B';
        return ans; 

    }
};
