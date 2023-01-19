class Solution {
    public int maximumGood(int[][] statements) {  
        int[] maxGoodPeople = {0};   
        maximumGood(statements, 
                    new boolean[statements.length],
                    0, 0, maxGoodPeople
                   );
        
        return maxGoodPeople[0];
    }
    
    void maximumGood(int[][] statements, 
                             boolean[] goodPeople, 
                             int currentPerson, 
                             int currentGoodPeople, 
                             int[] maxGoodPeople) {
        
        if (currentPerson == goodPeople.length) {
            maxGoodPeople[0] = Math.max(maxGoodPeople[0], currentGoodPeople);
            return;
        }
        
        goodPeople[currentPerson] = true;
        
        if (goodPeople.length - currentPerson + currentGoodPeople < maxGoodPeople[0]) {
            return;
        }
        
        if (isValid(statements, goodPeople, currentPerson)) {
            maximumGood(statements, goodPeople, 
                        currentPerson + 1,
                        currentGoodPeople + 1,
                        maxGoodPeople);
        }

        goodPeople[currentPerson] = false; 
        
        if (goodPeople.length - currentPerson - 1 + currentGoodPeople
            < maxGoodPeople[0]) {
            return;
        }
        
        if (isValid(statements, goodPeople, currentPerson)) {
            maximumGood(statements, goodPeople, 
                        currentPerson + 1, 
                        currentGoodPeople, 
                        maxGoodPeople);
        }
        
    }
    
    
    boolean isValid(int[][] statements, boolean[] goodPeople, int currentPerson) {
        for (int i = 0; i < currentPerson; i++) {
            if (goodPeople[i]) {
                if (goodPeople[currentPerson] && 
                    statements[i][currentPerson] == 0) {
                    return false;
                }
                if (!goodPeople[currentPerson] && 
                    statements[i][currentPerson] == 1) {
                    return false;
                }
            }
        }
        if (goodPeople[currentPerson]) {
            for (int i = 0; i < currentPerson; i++) {
                if (goodPeople[i] && 
                    statements[currentPerson][i] == 0) return false;
                if (!goodPeople[i] && 
                    statements[currentPerson][i] == 1) return false;
            }
        }

        return true;
    }
}
