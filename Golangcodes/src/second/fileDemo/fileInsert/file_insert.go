package main

import (
	"fmt"
	"io"
	"os"
)

func main() {
	fileObj, err := os.OpenFile("./sb.txt", os.O_RDWR, 0644)
	if err != nil {
		fmt.Printf("open file err: %v", err)
		return
	}
	defer fileObj.Close()
	tmpFile, err := os.OpenFile("./sb.tmp", os.O_TRUNC|os.O_CREATE|os.O_WRONLY, 0644)
	if err != nil {
		fmt.Printf("create tmp err:  %v", err)
		return
	}
	defer tmpFile.Close()

	var ret [2]byte
	n, err := fileObj.Read(ret[:])
	if err != nil {
		fmt.Printf("read error: %v", err)
		return
	}
	//fmt.Println(string(ret[:n]))
	tmpFile.Write(ret[:n])
	var s []byte = []byte{'p'}
	tmpFile.Write(s)

	var x [1024]byte
	for {
		n, err := fileObj.Read(x[:])
		if err == io.EOF {
			break
		}
		if err != nil {
			fmt.Printf("read file err:%v", err)
			return
		}
		tmpFile.Write(x[:n])
	}

	fileObj.Close()
	tmpFile.Close()

	os.Rename("./sb.tmp", "./sb.txt")

}
