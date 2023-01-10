class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_map<string,int>mp;
        for(auto it:rectangles)
        {
            string s1=to_string(it[0])+to_string(it[1]);  //Converted to string
            string s2=to_string(it[0])+to_string(it[3]);
            string s3=to_string(it[2])+to_string(it[1]);
            string s4=to_string(it[2])+to_string(it[3]);

            mp[s1]++;  //Stored in map
            mp[s4]++;

            mp[s2]--;
            mp[s3]--;

        }

     

            int c=0;
            for(auto it:mp)
            {
                if(it.second>0 or it.second<0)
                {
                    c++;
                    if(abs(it.second)!=1)
                        return false;
                }
                
               
            }

            return c==4;
       
      
    }
};