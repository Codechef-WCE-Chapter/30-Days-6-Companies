func evalRPN(tokens []string) int {
	var stack []int

	for _, token := range tokens {
		if token != "+" && token != "-" && token != "*" && token != "/" {
			num, _ := strconv.Atoi(token)
			stack = append(stack, num)
		} else {
			num1 := stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			num2 := stack[len(stack)-1]
			stack = stack[:len(stack)-1]

			switch token {
			case "+":
				stack = append(stack, num2+num1)
			case "-":
				stack = append(stack, num2-num1)
			case "*":
				stack = append(stack, num2*num1)
			case "/":
				stack = append(stack, num2/num1)

			}
		}

	}

	return stack[0]
}
