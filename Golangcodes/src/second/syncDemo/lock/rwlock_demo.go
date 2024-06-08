package main

import (
	"fmt"
	"sync"
	"time"
)

var x = 0
var wg sync.WaitGroup

// var lock sync.Mutex
var rwlock sync.RWMutex

func read() {
	defer wg.Done()
	rwlock.RLock()
	fmt.Println(x)
	time.Sleep(time.Millisecond)
	rwlock.RUnlock()

}

func write() {
	defer wg.Done()
	rwlock.Lock()
	x = x + 1
	time.Sleep(time.Millisecond)
	rwlock.Unlock()

}
func main() {
	now := time.Now()
	for i := 0; i < 30; i++ {
		go write()
		wg.Add(1)
	}
	for i := 0; i < 20000; i++ {
		go read()
		wg.Add(1)
	}
	wg.Wait()
	fmt.Println(time.Since(now))
}
