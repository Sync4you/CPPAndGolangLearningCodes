package main

import (
	"fmt"
	"time"
)

func main() {
	/* now := time.Now()
	fmt.Println(now.Date())
	fmt.Println(now.Day())
	fmt.Println(now.Hour())
	fmt.Println(now.Second())
	fmt.Println(now.Minute())
	fmt.Println(now.Unix())

	now = time.Unix(1810743055, 0)
	fmt.Println(now)
	*/
	/* timer := time.Tick(time.Second)
	for t := range timer {
		fmt.Println(t)
	} */

	timeObj, err := time.Parse("2006-01-02", "2006-01-02")
	if err != nil {
		fmt.Println(err)
	}

	fmt.Println(timeObj)

}
