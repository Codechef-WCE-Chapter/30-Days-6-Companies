class Solution {
    public List<String> invalidTransactions(String[] transactions) {
        
        int n = transactions.length;
        
        String[] name = new String[n];
        int[] time = new int[n];
        int[] amount = new int[n];
        String[] city = new String[n];
        
        for(int i = 0; i < n; i++) {
            
            String[] parts = transactions[i].split(",");
            
            name[i] = parts[0];
            time[i] = Integer.parseInt(parts[1]);
            amount[i] = Integer.parseInt(parts[2]);
            city[i] = parts[3];
            
        }
        
        List<String> ans = new ArrayList<>();
        boolean[] notValid = new boolean[n];
        
        for(int i = 0; i < n; i++) {
            
            boolean flag = true;
            
            if(amount[i] > 1000) notValid[i] = true;
            
            for(int j = 0; j < i; j++) {
                if(name[i].equals(name[j]) && !city[i].equals(city[j])) {
                    if(Math.abs(time[i] - time[j]) <= 60) {
                        notValid[i] = true;
                        notValid[j] = true;
                    }
                }
            }
            
        }
        
        for(int i = 0; i < n; i++) {
            if(notValid[i]) ans.add(transactions[i]);
        }
        
        return ans;
        
    }
}
