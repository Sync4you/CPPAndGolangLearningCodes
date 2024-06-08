package main

import (
	"fmt"
	"net"
	"strings"
)

func main() {
	conn, err := net.ListenUDP("udp", &net.UDPAddr{
		IP:   net.IPv4(127, 0, 0, 1),
		Port: 40000,
	})
	if err != nil {

		fmt.Println("listen udp:", err)
		return
	}
	defer conn.Close()
	var data [1024]byte
	for {
		n, addr, err := conn.ReadFromUDP(data[:])
		if err != nil {

			fmt.Println("read udp,", err)
			return
		}
		reply := strings.ToUpper(string(data[:n]))
		fmt.Println(data[:n])
		conn.WriteToUDP([]byte(reply), addr)

	}
}
