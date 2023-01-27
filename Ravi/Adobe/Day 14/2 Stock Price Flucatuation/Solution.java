class StockPrice {

    TreeMap<Integer, Integer> tm;
    HashMap<Integer, Integer> hm;
    int curr = 0;
    int maxm = 0;
    public StockPrice() {
        tm = new TreeMap<>();
        hm = new HashMap<>();
    }
    
    public void update(int timestamp, int price) {
        if(hm.containsKey(timestamp)) {
            int oldPrice = hm.get(timestamp);
            tm.put(oldPrice, tm.get(oldPrice) - 1);
            if(tm.get(oldPrice) == 0) tm.remove(oldPrice);
        }
        
        hm.put(timestamp, price);
        tm.put(price, tm.getOrDefault(price, 0) + 1);
        if(timestamp >= maxm) {
            maxm = timestamp;
            curr = price;
        }
        
    }
    
    public int current() {
        return curr;
    }
    
    public int maximum() {
        return tm.lastKey();
    }
    
    public int minimum() {
        return tm.firstKey();
    }
}
