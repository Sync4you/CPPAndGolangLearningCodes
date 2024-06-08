package splitstringdemo

import (
	"strings"
	
)

func Split(str string, sep string) []string {
	var ret []string
	index := strings.Index(str, sep)
	for index >= 0 {
		ret = append(ret, str[:index])
		str = str[index+len(sep):]
		index = strings.Index(str, sep)
	}
	ret = append(ret, str)
	return ret
}

/* func main() {
	ret := Split("bacawdwbgbb", "b")
	fmt.Println(ret)

	ret = Split("daddddddddoolkdadd", "dd")
	fmt.Println(ret)
} */
