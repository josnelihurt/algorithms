package hacker_rank

func findMax(a []int32) int32 {
	max := a[0]
	for _, value := range a {
		if value > max {
			max = value
		}
	}
	return max
}

//anyOfMatches ported from my solution using cpp, it doesn't seem to be any built in func like this
//https://en.cppreference.com/w/cpp/algorithm/all_any_none_of
func anyOfMatches(s []int32, matcher func(it int32) bool) bool {
	for _, v := range s {
		if m := matcher(v); m == true {
			return true
		}
	}
	return false
}

func getTotalX(a, b []int32) int32 {
	result := []int32{}
	max := findMax(append(a, b...))
	for i := int32(1); i <= max; i++ {
		if anyOfMatches(a, func(it int32) bool {
			return i%it != 0
		}) {
			continue
		}
		if anyOfMatches(b, func(it int32) bool {
			return it%i != 0
		}) {
			continue
		}
		result = append(result, i)
	}

	return int32(len(result))
}
