package main

import (
	"fmt"
	"sync"
	"sync/atomic"
)

var x int64
var wg sync.WaitGroup

//var lock sync.Mutex

func add() {
	atomic.AddInt64(&x, 1)
	wg.Done()
}

func main() {
	wg.Add(1000)
	for i := 0; i < 1000; i++ {
		go add()

	}
	wg.Wait()
	fmt.Println(x)
	ok := atomic.CompareAndSwapInt64(&x, 10, 150)
	fmt.Printf("%d %v", x, ok)
}
