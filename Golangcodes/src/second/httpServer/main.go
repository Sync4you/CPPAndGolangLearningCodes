package main

import (
	"net/http"
)

func f1(w http.ResponseWriter, r *http.Request) {
	str := "hello"
	w.Write([]byte(str))
}
func main() {
	http.HandleFunc("/post", f1)
	http.ListenAndServe("127.0.0.1:9090", nil)
}
