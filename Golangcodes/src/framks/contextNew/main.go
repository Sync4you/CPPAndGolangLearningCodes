package main

// refer to https://www.bilibili.com/video/BV1Rh411P7oN/?spm_id_from=333.999.0.0&vd_source=cab86442f91582a72a20a6d1a3799665
import (
	"context"
	"fmt"
	"time"
	//"time"
)

type mystring string

func funName(ctx context.Context) context.Context {
	child := context.WithValue(ctx, mystring("name"), "Peter")
	return child
}

func funAge(ctx context.Context) context.Context {
	child := context.WithValue(ctx, mystring("age"), 2020)
	return child
}
func showInfo(ctx context.Context) {
	fmt.Printf("name is :%s\n", ctx.Value(mystring("name")))
	fmt.Printf("age is :%d\n", ctx.Value(mystring("age")))
}
func f1() {
	ctx1, cancel1 := context.WithTimeout(context.TODO(), time.Millisecond*1000)
	defer cancel1()
	t0 := time.Now()
	time.Sleep(time.Millisecond * 500)
	ctx2, cancel2 := context.WithTimeout(ctx1, time.Millisecond*1000)
	defer cancel2()
	t1 := time.Now()
	<-ctx2.Done()
	err := ctx2.Err()
	t2 := time.Now()
	fmt.Println(t2.Sub(t0).Milliseconds(), t2.Sub(t1).Milliseconds())
	fmt.Println(err)
}
func main() {
	gen1 := context.TODO()
	gen2 := funName(gen1)
	gen3 := funAge(gen2)
	showInfo(gen3)
	f1()
}
