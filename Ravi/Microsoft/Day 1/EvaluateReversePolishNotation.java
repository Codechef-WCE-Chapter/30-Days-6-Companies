class Solution {
    public int evalRPN(String[] tokens) {
        
        Stack<Integer> st = new Stack<>();
        
        for(String s : tokens) {
            try {
                
                // It will return the integer if possible or will sent the flow to catch block
                int a = Integer.parseInt(s);
                st.push(a);
            } catch(Exception e) {
                
                // We will pop the first two integers from the stack
                int a = st.pop();
                int b = st.pop();
                
                // We will check which operation we need to perform on the operands and will perform those pperations
                if(s.charAt(0) == '+') st.push(a + b);
                else if(s.charAt(0) == '-') st.push(b - a);
                else if(s.charAt(0) == '*') st.push(b * a);
                else st.push(b / a);
                
            }
        }
        
        return st.pop();
    }
}
