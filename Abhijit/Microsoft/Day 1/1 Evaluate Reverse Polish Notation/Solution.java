class Solution {
    public int evalRPN(String[] tokens) {

        // - whenever we get operator, we have 
        //   to perform that operation on lastly added 
        //   two operands
        // - This means we need some data structure
        //   using which we can access the elements
        //   added at last in less time
        // -  Stack it is 

        // 1) If we get a operand, push it in the stack
        // 2) If we get a operator, pop two elements 
        //    from stack, perform the required 
        //    operation and push result in stack
        
        // Finally if expression is valid, we will get
        // single element in the stack which will be
        // the answer


        Stack<Integer> stack = new Stack<>() ;

        for(String token: tokens){
            // operator ==> pop two elements, perrorm
            // operation and push result in stack
            if(token.equals("+")){
                int b = stack.pop() ;
                int a = stack.pop() ;
                stack.add(a+b) ;
            } else if(token.equals("-")){
                int b = stack.pop() ;
                int a = stack.pop() ;
                stack.add(a-b) ;
            } else if(token.equals("*")){
                int b = stack.pop() ;
                int a = stack.pop() ;
                stack.add(a*b) ;
            } else if(token.equals("/")){
                int b = stack.pop() ;
                int a = stack.pop() ;
                stack.add(a/b) ;
            } 
            // operand ==> push in the stack
            else {
                stack.add(Integer.parseInt(token)) ;
            }
        }
        
        return stack.peek() ;
    }
}
