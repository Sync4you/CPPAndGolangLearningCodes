package main

import (
	"fmt"
	"sync"
)

var wg sync.WaitGroup
var once sync.Once

func initChan(ch1 chan int) {
	defer wg.Done()
	for x := 0; x < 100; x++ {
		ch1 <- x
	}
	close(ch1)
}

func sentChan(ch1, ch2 chan int) {
	defer wg.Done()
	for {
		x, ok := <-ch1
		if !ok {
			break
		}
		ch2 <- x * 2
	}
	once.Do(func ()  {
		close(ch2)
	})
	//ensure do once
	//close(ch2)
}

func main() {
	ch1 := make(chan int, 100)
	ch2 := make(chan int, 100)
	wg.Add(3)

	go initChan(ch1)
	go sentChan(ch1, ch2)
	go sentChan(ch1, ch2)

	wg.Wait()

	for ret := range ch2 {
		fmt.Printf(" %d", ret)
	}

	/* var b chan int
	//var a []int
	var wg sync.WaitGroup
	b = make(chan int)
	wg.Add(1)
	go func() {
		defer wg.Done()
		x := <-b
		fmt.Println("goroutine 取到了：", x)
	}()
	b <- 10
	fmt.Println("10 SENT TO CHANNEL")
	fmt.Println(b)
	wg.Wait() */
	//fmt.Println(a)

}
