package main

import (
	"net"
	"fmt"
	proto "second/stickPackageDemo/proto/proto.go"
)

func main() {
	conn, err := net.Dial("tcp", "127.0.0.1:20000")
	if err != nil {
		return
	}
	defer conn.Close()
	for i := 0; i < 20; i++ {
		msg := `hello how old are you!`
		b, _ = proto.Encode(msg)
		conn.Write(b)

	}
}
