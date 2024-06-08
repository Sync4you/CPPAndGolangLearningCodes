package main

import (
	"fmt"

	"github.com/go-redis/redis"
)

var redisDb *redis.Client

func initRedis() (err error) {
	redisDb = redis.NewClient(&redis.Options{
		Addr:     "127.0.0.1:6379",
		Password: "",
		DB:       0,
	})
	_, err = redisDb.Ping().Result()
	return
}
func main() {
	err := initRedis()
	if err != nil {
		fmt.Printf("connect redis err:%v", err)
		return
	}
	fmt.Println("success in connection")
	key := "rank"
	items := []redis.Z{
		{Score: 90.0, Member: "java"},
		{Score: 97.0, Member: "golang"},
		{Score: 91.0, Member: "python"},
		{Score: 87.0, Member: "C++"},
		{Score: 99.0, Member: "Rust"},
	}
	num, err := redisDb.ZAdd(key, items...).Result()
	if err != nil {
		fmt.Printf("zadd fail, err:%v\n", err)
		return
	}
	fmt.Printf("zadd %d succ", num)

}
