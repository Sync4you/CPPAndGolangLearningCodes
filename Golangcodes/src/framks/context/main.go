package main

import (
	"context"
	"fmt"
	"sync"
	"time"
)

var wg sync.WaitGroup


func f(ctx context.Context) {
	defer wg.Done()
FORLOOP:
	for {
		fmt.Println("jack")
		time.Sleep(time.Millisecond * 200)
		select {
		case <-ctx.Done():
			break FORLOOP
		default:
		}
	}
}

func f1(ctx context.Context) {
	defer wg.Done()
	go f(ctx)
FORLOOP:
	for {
		fmt.Println("peter")
		time.Sleep(time.Millisecond * 200)
		select {
		case <-ctx.Done():
			break FORLOOP
		default:
		}
	}
}
func main() {
	ctx, cancel := context.WithCancel(context.Background())

	wg.Add(1)
	go f1(ctx)
	time.Sleep(time.Second * 3)
	cancel()
	wg.Wait()

}
