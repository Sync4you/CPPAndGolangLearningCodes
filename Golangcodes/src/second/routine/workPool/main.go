package main

import (
	"math/rand"
	"fmt"
	"sync"
	"time"
)

type Job struct {
	x int64
}

type Result struct {
	job    *Job
	result int64
}

var jobChan = make(chan *Job, 100)
var resultChan = make(chan *Result, 100)
var wg sync.WaitGroup

func sentJobChan(i chan<- *Job) {
	defer wg.Done()
	for {
		x := rand.Int63()
		newjob := &Job{x}
		i <- newjob
		time.Sleep(time.Millisecond * 5)
	}
}

func calJobChan(i <-chan *Job, res chan<- *Result) {
	defer wg.Done()
	for {
		job := <-i
		sum := int64(0)
		n := job.x
		for n > 0 {
			sum += n % 10
			n = n / 10
		}
		newRes := &Result{
			job:    job,
			result: sum,
		}
		res <- newRes
	}
}
func main() {
	wg.Add(1)
	go sentJobChan(jobChan)

	wg.Add(24)
	for i := 0; i < 24; i++ {
		go calJobChan(jobChan, resultChan)
	}

	for res := range resultChan {
		fmt.Printf("value : %d, sum : %d", res.job.x, res.result)
	}
	wg.Wait()
}
