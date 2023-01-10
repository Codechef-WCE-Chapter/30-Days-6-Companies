class Solution:
    def evalRPN(self, tokens: list[str]) -> int:
        stack=[]
        for i in tokens:
            if i in '+-*/': a,b=stack.pop(),stack.pop()
            if i == '+': stack.append(b+a)
            elif i == '-': stack.append(b-a)
            elif i == '*': stack.append(b * a)
            elif i == '/': stack.append(int(b/a))
            else: stack.append(int(i))
        return stack[0]