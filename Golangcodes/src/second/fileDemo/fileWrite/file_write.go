package main

import (
	"bufio"
	"fmt"
	"os"
)

func writeFile1() {
	fileObj, err := os.OpenFile("./data.file", os.O_WRONLY|os.O_CREATE|os.O_TRUNC, 0644)
	if err != nil {
		fmt.Printf("open file error :%v\n", err)
		return
	}
	defer fileObj.Close()
	wr := bufio.NewWriter(fileObj)
	wr.WriteString("hello fuck you\n")
	wr.Flush()

}

func fseek() {
	fileObj, err := os.OpenFile("./sb.txt", os.O_RDWR, 0644)
	if err != nil {
		fmt.Printf("OPEN FILE FAILD:%v", err)
	}
	defer fileObj.Close()
	fileObj.Seek(1, 0)
	var ret [1]byte
	n, err := fileObj.Read(ret[:])
	if err != nil {
		fmt.Println("READ FAILED: ", err)
		return
	}
	fmt.Println(string(ret[:n]))

}
func main() {
	writeFile1()
	fseek()
}
