package main

import (
	"bufio"
	"fmt"
	"net"
	"os"
	"strings"
)

func main() {
	conn, err := net.Dial("tcp", "127.0.0.1:20001")
	if err != nil {
		fmt.Println("dial err", err)
		return
	}
	reader := bufio.NewReader(os.Stdin)
	for {
		fmt.Println("please speak")
		msg, _ := reader.ReadString('\n')
		msg = strings.TrimSpace(msg)
		if msg == "exit" {
			break
		}
		conn.Write([]byte(msg))
	}

	conn.Close()

}
