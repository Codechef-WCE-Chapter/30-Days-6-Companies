package main

import "strconv"

func getHint(secret string, guess string) string {
	bulls, cows := 0, 0
	freq := make(map[int]int)

	for i := 0; i < len(secret); i++ {
		if secret[i] == guess[i] {
			bulls++
		} else {
			if freq[int(secret[i])] < 0 {
				cows++
			}
			freq[int(secret[i])]++

			if freq[int(guess[i])] > 0 {
				cows++
			}
			freq[int(guess[i])]--
		}
	}

	return strconv.Itoa(bulls) + "A" + strconv.Itoa(cows) + "B"
}

func main() {
	secret := "1807"
	guess := "7810"

	println(getHint(secret, guess))
}
