class Solution {
    
    public List<String> invalidTransactions(String[] transactions) {
        
        List<Transaction> transactionsList = new ArrayList<>() ;
        
        for(String t: transactions) {
            String[] arr = t.split(",") ;
            String name = arr[0] ;
            int time = Integer.parseInt(arr[1]) ;
            int amount = Integer.parseInt(arr[2]) ;
            String city = arr[3] ;
            Transaction tran = new Transaction(t, name, time, amount, city, true) ;
            transactionsList.add(tran) ;
        }
        
        for(Transaction t: transactionsList) {
            if(t.amount > 1000){
                t.isValid = false ;
            }
        }
        
        for(Transaction t: transactionsList) {
            for(Transaction t2: transactionsList) {
                if(t == t2){
                    continue ;
                }
                
                if(t.name.equals(t2.name) && !t2.city.equals(t.city) 
                   && Math.abs(t.time - t2.time) <= 60) {
                    t.isValid = false ;
                }
            }
        }
        
        List<String> invalidTransactions = new ArrayList<>() ;
        for(Transaction t: transactionsList) {
            if(!t.isValid){
                invalidTransactions.add(t.transactionString) ;
            }
        }
        
        return invalidTransactions ;
    }
    
}

class Transaction {
    String transactionString;
    String name;
    int time ;
    int amount;
    String city ;
    boolean isValid;
    
    Transaction(String str, String name, int time, int amount, String city, boolean isValid) {
        this.transactionString = str ;
        this.name = name ;
        this.time = time ;
        this.amount = amount ;
        this.city = city ;
        this.isValid = isValid ;
    }
}
