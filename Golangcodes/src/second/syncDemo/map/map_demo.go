package main

import (
	"fmt"
	"strconv"
	"sync"
)

// var m = make(map[string]int)
var m2 = sync.Map{}

//var lock sync.Mutex

/* func get(key string) int {
	return m[key]
}

func set(key string, value int) {
	m[key] = value
} */

func main() {
	wg := sync.WaitGroup{}
	for i := 0; i < 200; i++ {
		wg.Add(1)
		go func(n int) {
			key := strconv.Itoa(n)
			//lock.Lock()
			m2.Store(key, n)
			value, _ := m2.Load(key)
			//set(key, n)
			//lock.Unlock()
			fmt.Printf("K =%v, v=%v\n", key, value)
			wg.Done()
		}(i)
	}
	wg.Wait()

}
