class TweetCounts {

    HashMap<String, TreeMap<Integer, Integer>> hm = new HashMap<>();
    public TweetCounts() {
        
    }
    
    public void recordTweet(String tweetName, int time) {
        
        TreeMap<Integer, Integer> tm = hm.getOrDefault(tweetName, new TreeMap<>());
        tm.put(time, tm.getOrDefault(time, 0) + 1);
        
        hm.put(tweetName, tm);
        
        
    }
    
    public List<Integer> getTweetCountsPerFrequency(String freq, String tweetName, int startTime, int endTime) {
        
        TreeMap<Integer, Integer> tm = hm.getOrDefault(tweetName, new TreeMap<>());
        int f = 60;
        if(freq.equals("hour")) f = 3600;
        else if(freq.equals("day")) f = 86400;
        
        int prev = startTime;
        int curr = 0;
        
        List<Integer> ans = new ArrayList<>();
        
        for(int i : tm.keySet()) {
            if(i < startTime) continue;
            if(i > endTime) break;
            
            if(i < prev + f) curr += tm.get(i);
            else {
                while(i >= prev + f) {
                    ans.add(curr);
                    curr = 0;
                    prev += f;
                }
                curr += tm.get(i);
            }
        }
        
        ans.add(curr);
        prev += f;
        curr = 0;
        while(prev <= endTime) {
            ans.add(curr);
            prev += f;
        }
        
        return ans;
        
    }
}

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts obj = new TweetCounts();
 * obj.recordTweet(tweetName,time);
 * List<Integer> param_2 = obj.getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
