package main

import (
	"fmt"
	"net"
)

func processConn(conn net.Conn) {
	var tmp [512]byte

	for {
		n, err := conn.Read(tmp[:])
		if err != nil {
			fmt.Println("read err:", err)
			return
		}
		fmt.Println(string(tmp[:n]))
	}
}
func main() {
	listener, err := net.Listen("tcp", "127.0.0.1:20001")
	if err != nil {
		fmt.Println("listen err", err)
		return
	}

	for {
		conn, err := listener.Accept()
		if err != nil {
			fmt.Println("accept err:", err)
			return
		}
		go processConn(conn)
	}

}
