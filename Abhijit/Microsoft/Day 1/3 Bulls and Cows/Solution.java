class Solution {
    public String getHint(String secret, String guess){
        int[] freq = new int[10] ;

        // store frequency of every character in secret
        for(char ch: secret.toCharArray()) {
            freq[ch - '0']++ ;
        }

        int bulls = 0, cows = 0 ;

        for(int i = 0; i < guess.length(); i++) {
            // if charcters at ith pos match, we get a
            // bull, decrease the frequency because 
            // it can't be matched to other characters
            if(guess.charAt(i) == secret.charAt(i)){
                bulls++ ;
                freq[guess.charAt(i) - '0']-- ;
            }
        }

        for(int i = 0; i < guess.length(); i++) {
            // if they don't match, check if frequency
            // of cur guess character is positive in
            // freq array i.e. that charcter is present
            // somewhere in secret. Again decrese 
            // freqency of charcter we considered.
            if(secret.charAt(i) != guess.charAt(i)
                    && freq[guess.charAt(i) - '0'] > 0{
                cows++ ;
                freq[guess.charAt(i) - '0']-- ;
            }
        }

        return bulls+ "A" + cows + "B" ;
    }
}
