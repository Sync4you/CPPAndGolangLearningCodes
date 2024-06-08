package main

import (
	"database/sql"
	"fmt"

	_ "github.com/go-sql-driver/mysql"
)

var db *sql.DB

type user struct {
	id   int
	name string
	age  int
}

func initDB() (err error) {
	dsn := "root:123456@tcp(127.0.0.1:3306)/go_db"
	db, err = sql.Open("mysql", dsn)
	if err != nil {
		fmt.Println("dsn:failed:", err)
		return err
	}
	err = db.Ping()
	if err != nil {
		fmt.Println("OPEN FAILED")
		return err
	}
	fmt.Println("connect success!")
	db.SetMaxOpenConns(10)
	db.SetMaxIdleConns(5)
	return nil
}

func queryOne(id int) {
	var u1 user
	sqlstr := `select id, name, age from user where id=?;`
	rowObj := db.QueryRow(sqlstr, id)
	rowObj.Scan(&u1.id, &u1.name, &u1.age)
	fmt.Printf("user1: %#v\n", u1)
}

func queryMore(id int) {
	sqlstr := `select id, name, age from user where id >= ?;`
	rows, err := db.Query(sqlstr, id)
	if err != nil {
		fmt.Println("query err:", err)
		return
	}
	defer rows.Close()
	for rows.Next() {
		var u1 user
		err := rows.Scan(&u1.id, &u1.name, &u1.age)
		if err != nil {
			fmt.Println("scan err", err)
		}
		fmt.Printf("user:%v\n", u1)
	}
}
func insert(name string, age int) {
	sqlstr := `insert into user(name, age) values(?, ?);`
	ret, err := db.Exec(sqlstr, name, age)
	if err != nil {

		fmt.Println("insert err:", err)
		return
	}
	id, err := ret.LastInsertId()
	if err != nil {
		fmt.Println("get id failed:", err)
		return
	}
	fmt.Println("inserted id :", id)
}
func updateRow(age int, id int) {
	sqlstr := `update user set age=? where id=?;`
	ret, err := db.Exec(sqlstr, age, id)
	if err != nil {
		fmt.Println("update err", err)
		return
	}
	n, err := ret.RowsAffected()
	if err != nil {
		fmt.Println("get row affect err", err)
		return
	}
	fmt.Printf("updated %d rows\n", n)
}

func deleteRow(id int) {
	sqlstr := `delete from user where id = ?;`
	ret, err := db.Exec(sqlstr, id)
	if err != nil {
		fmt.Println("delete err", err)
		return
	}
	n, err := ret.RowsAffected()
	if err != nil {
		fmt.Println("get row affect err", err)
		return
	}
	fmt.Printf("deleted %d rows\n", n)
}
func prepareInsert() {
	sqlstr := `insert into user(name, age) values(?, ?);`
	stmt, err := db.Prepare(sqlstr)
	if err != nil {
		fmt.Println("prepare failed", err)
		return
	}
	defer stmt.Close()
	var m = map[string]int{
		"李四": 25,
		"王五": 30,
		"赵六": 77,
	}
	for k, v := range m {
		stmt.Exec(k, v)
	}

}
func transactionDemo() {
	tx, err := db.Begin()
	if err != nil {
		fmt.Println("begin err:", err)
		return
	}
	str1 := `update user set age = age - 2 where id = 3;`
	str2 := `update user set age = age + 2 where id = 1;`
	_, err = tx.Exec(str1)
	if err != nil {
		tx.Rollback()
	}
	_, err = tx.Exec(str2)
	if err != nil {
		tx.Rollback()
	}
	err = tx.Commit()
	if err != nil {
		tx.Rollback()
		fmt.Println("roll back:", err)
		return
	}
	fmt.Println("success!")
}
func main() {
	err := initDB()
	if err != nil {
		fmt.Println("init db error:", err)
	}
	fmt.Println("connect database success!")

	queryOne(1)
	queryMore(1)
	insert("张三", 22)
	updateRow(18, 3)
	deleteRow(2)
	prepareInsert()
	transactionDemo()
}
