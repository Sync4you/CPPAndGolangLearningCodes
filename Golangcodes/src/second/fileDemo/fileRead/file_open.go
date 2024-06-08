package main

import (
	"bufio"
	"fmt"
	"io"
	"io/ioutil"
	"os"
)

func readFile() {
	fileObj, err := os.Open("./file_open.go")
	if err != nil {
		fmt.Println(("open file failed!"), err)
		defer fileObj.Close()
	}
	var tmp [1024]byte
	n, err := fileObj.Read(tmp[:])
	if err != nil {
		fmt.Println("read file error", err)
		return
	}
	fmt.Printf("read %d byte\n", n)
	fmt.Println("read is :", string(tmp[:n]))
}

func readFileFromBufio() {
	fileObj, err := os.Open("./file_open.go")
	if err != nil {
		fmt.Println("open file error", err)
		return
	}
	defer fileObj.Close()
	reader := bufio.NewReader(fileObj)
	for {
		line, err := reader.ReadString('\n')
		if err == io.EOF {
			return
		}
		if err != nil {
			fmt.Print("read line error\n", err)
			return
		}
		fmt.Print(line)
	}
}

func readFileFromIoutil() {
	ret, err := ioutil.ReadFile("./file_open.go")
	if err != nil {
		fmt.Printf("read error %v\n", err)
		return
	}
	fmt.Println(string(ret))
}

func getInput() {
	var s string
	reader := bufio.NewReader(os.Stdin)
	s, _ = reader.ReadString('\n')
	fmt.Printf("your input is :%s", s)
}
func main() {
	readFile()
	readFileFromBufio()
	readFileFromIoutil()
	getInput()
}
