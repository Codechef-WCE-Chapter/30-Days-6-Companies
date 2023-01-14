class Solution {
public:
// time 0(logn)

/* Approach:

if any number has trailing zeros then 
that number must have 5 
So the number of 5's it will contain will
 be the count of trailing zeros

 */
int trailingZeroes(int n) {
int cnt =0;

while(n){
    n = n/5;
    cnt += n;
}

return cnt;
}

// This will take O(n) time
/*
long long int fact(int n){
    if(n ==0){
        return 1;
    }
    else
    return fact(n-1)*n;
}
int trailingZeroes(int n) {
       long long int ans = fact(n);
     int cnt =0;
    
        for(int i = 0; i <n; i++){
            
            if(ans % 10 == 0 && ans>10){
                cnt++;
            }
            else{
                break;
            }
            ans = ans/10;
            
        }

        return cnt;
    }

    */
};
