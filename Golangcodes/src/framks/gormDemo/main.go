package main

import (
	"fmt"
	"gorm.io/driver/mysql"
	"gorm.io/gorm"
)

var db *gorm.DB
var err error
type User struct{
	Id int32
	Name string
	Age int
}

func (m *User) TableName()string {
	return "User"
}

func initConn () string {
	dsn := "root:123456@tcp(127.0.0.1:3306)/go_db?charset=utf8mb4&parseTime=True&loc=Local"
	db, err = gorm.Open(mysql.Open(dsn), &gorm.Config{})
	if err != nil {
		return err.Error()
	}
	return "connection success!"
}
func getUserList () {
	var userList []User
	// result := db.Find(&userList)
	// fmt.Println(result.RowsAffected)
	db.Where("age >= 30").Find(&userList)
	fmt.Println(userList)
}

func editUserList(){
	user := User{Id: 1}
	db.Find(&user)
	user.Name = "Jason"
	db.Save(&user)
	fmt.Println("修改成功")
}
func deleteUserList () {
	user := User{}
	db.Where("name = ?", "Jason").Delete(&user)
	fmt.Println("删除成功")
}
func addUserList () {
	user := User{
		Id: 1,
		Name: "Jack",
		Age: 26,
	}
	db.Create(&user)
	fmt.Println("增加成功")
}
func main() {
	initConn()
	getUserList()
	//editUserList()
	//deleteUserList()
	//addUserList()
}