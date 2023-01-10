class Solution {
    public String getHint(String secret, String guess) {
        
        int n = secret.length();
        
        StringBuilder sb = new StringBuilder("");
        
        int curr = 0;
        for(int i = 0; i < n; i++) {
            if(secret.charAt(i) == guess.charAt(i)) curr++;
        }
        
        sb.append(curr);
        sb.append('A');
        
        HashMap<Character, Integer> hm = new HashMap<>();
        for(int i = 0; i < n; i++) {
            hm.put(secret.charAt(i), hm.getOrDefault(secret.charAt(i), 0) + 1);
        }
        
        for(int i = 0; i < n; i++) {
            if(hm.containsKey(guess.charAt(i))) {
                curr--;
                hm.put(guess.charAt(i), hm.get(guess.charAt(i)) - 1);
                if(hm.get(guess.charAt(i)) == 0) hm.remove(guess.charAt(i));
            }
        }
        
        curr *= -1;
        sb.append(curr);
        sb.append('B');
        
        return sb.toString();
        
    }
}
