class Solution {
    public List<List<String>> mostPopularCreator(String[] creators, String[] ids, int[] views) {
        
        HashMap<String, Long> hm = new HashMap<>();
        
        for(int i = 0; i < creators.length; i++) {
            hm.put(creators[i], hm.getOrDefault(creators[i], 0l) + views[i]);
        }
        
        long maxm = 0;
        for(String s : hm.keySet()) {
            maxm = Math.max(maxm, hm.get(s) * 1L);
        }
        
        // System.out.println(maxm);
        
        HashSet<String> hs = new HashSet<>();
        for(String s : hm.keySet()) {
            if(hm.get(s) * 1L == maxm) hs.add(s);
        }
        
        // System.out.println(hm.get("a"));
        
        // for(String s : hs) System.out.println(s);
        
        HashMap<String, Long> hmm = new HashMap<>();
        for(int i = 0; i < creators.length; i++) {
            if(hs.contains(creators[i])) {
                hmm.put(creators[i], Math.max(hmm.getOrDefault(creators[i], 0l), views[i]));
            }
        }
        
        // System.out.println(hmm.size());
        // for(String sss : hmm.keySet()) {
        //     System.out.println(sss + " " + hmm.get(sss));
        //                 }
        
        HashMap<String, String> hm2 = new HashMap<>();
        for(int i = 0; i < creators.length; i++) {
            if(hmm.containsKey(creators[i]) && hmm.get(creators[i]) == views[i]) {
                if(!hm2.containsKey(creators[i])) hm2.put(creators[i], ids[i]);
                String c = hm2.get(creators[i]);
                String d = ids[i];
                if(c.compareTo(d) > 0) hm2.put(creators[i], d);
            }
        }
        
        List<List<String>> ans = new ArrayList<>();
        for(String ss : hm2.keySet()) {
            List<String> curr = new ArrayList<>();
            curr.add(ss);
            curr.add(hm2.get(ss));
            ans.add(curr);
        }
        
        return ans;
        
        
    }
}
