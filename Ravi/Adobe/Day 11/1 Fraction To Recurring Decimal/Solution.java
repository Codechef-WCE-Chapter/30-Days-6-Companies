class Solution {
    
    StringBuilder ans = new StringBuilder("");
    
    public String fractionToDecimal(int numerator, int denominator) {
        
        long remainder = -1;
        
        if(numerator > 0 && denominator < 0 || numerator < 0 && denominator > 0) ans.append("-");
        
        long num = Math.abs((long)numerator);
        long den = Math.abs((long)denominator);
        
        ans.append(num / den);
    
        remainder = num % den;
        
        if(remainder == 0) return ans.toString();
        
        ans.append('.');
        
        HashMap<Long, Integer> hm = new HashMap<>();
        
        long q = -1;
        
        while(!hm.containsKey(remainder)) {
            hm.put(remainder, ans.length());
            num = remainder * 10;
            q = num / den;
            remainder = num % den;
            ans.append(q);
            if(remainder == 0) return ans.toString();
        }
        
        ans.insert(hm.get(remainder), "(");
        ans.append(')');
        return ans.toString();
        
    }
}


