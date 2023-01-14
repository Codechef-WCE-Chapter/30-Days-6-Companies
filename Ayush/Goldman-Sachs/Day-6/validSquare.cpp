#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) 
        {
            if(p1[0]==p2[0]&&p1[1]==p2[1])return false;
            else if(p1[0]==p3[0]&&p1[1]==p3[1])return false;
            else if(p1[0]==p4[0]&&p1[1]==p4[1])return false;
            else if(p3[0]==p2[0]&&p3[1]==p2[1])return false;
            else if(p4[0]==p2[0]&&p4[1]==p2[1])return false;
            else if(p4[0]==p3[0]&&p4[1]==p3[1])return false;
            long long digdist,p,q;
            p=(p2[0]-p1[0])*(p2[0]-p1[0])+(p2[1]-p1[1])*(p2[1]-p1[1]);
            q=(p3[0]-p1[0])*(p3[0]-p1[0])+(p3[1]-p1[1])*(p3[1]-p1[1]);
            if(p>q)
            {
                digdist=p;
                if(p!=2*q)return false;
                p=(p4[0]-p1[0])*(p4[0]-p1[0])+(p4[1]-p1[1])*(p4[1]-p1[1]);
                if(p!=q)return false;
            }
            else if(p<q)
            {
                digdist=q;
                if(q!=2*p)return false;
                q=(p4[0]-p1[0])*(p4[0]-p1[0])+(p4[1]-p1[1])*(p4[1]-p1[1]);
                if(q!=p)return false;
            }
            else
            {
                digdist=(p4[0]-p1[0])*(p4[0]-p1[0])+(p4[1]-p1[1])*(p4[1]-p1[1]);
                if(digdist!=2*p)return false;
            }
            p=(p2[0]-p1[0])*(p2[0]-p1[0])+(p2[1]-p1[1])*(p2[1]-p1[1]);
            q=(p2[0]-p3[0])*(p2[0]-p3[0])+(p2[1]-p3[1])*(p2[1]-p3[1]);
            if(p>q)
            {
                if(digdist!=p)return false;
                if(p!=2*q)return false;
                p=(p4[0]-p2[0])*(p4[0]-p2[0])+(p4[1]-p2[1])*(p4[1]-p2[1]);
                if(p!=q)return false;
            }
            else if(p<q)
            {
                if(digdist!=q)return false;
                if(q!=2*p)return false;
                q=(p4[0]-p2[0])*(p4[0]-p2[0])+(p4[1]-p2[1])*(p4[1]-p2[1]);
                if(q!=p)return false;
            }
            else
            {
                q=(p4[0]-p2[0])*(p4[0]-p2[0])+(p4[1]-p2[1])*(p4[1]-p2[1]);
                if(digdist!=q)return false;
            }
            p=(p3[0]-p1[0])*(p3[0]-p1[0])+(p3[1]-p1[1])*(p3[1]-p1[1]);
            q=(p2[0]-p3[0])*(p2[0]-p3[0])+(p2[1]-p3[1])*(p2[1]-p3[1]);
            if(p>q)
            {
                if(digdist!=p)return false;
                if(p!=2*q)return false;
                p=(p4[0]-p3[0])*(p4[0]-p3[0])+(p4[1]-p3[1])*(p4[1]-p3[1]);
                if(p!=q)return false;
            }
            else if(p<q)
            {
                if(digdist!=q)return false;
                if(q!=2*p)return false;
                q=(p4[0]-p3[0])*(p4[0]-p3[0])+(p4[1]-p3[1])*(p4[1]-p3[1]);
                if(q!=p)return false;
            }
            else
            {
                q=(p4[0]-p3[0])*(p4[0]-p3[0])+(p4[1]-p3[1])*(p4[1]-p3[1]);
                if(digdist!=q)return false;
            }
            
            return true;
        }   
};