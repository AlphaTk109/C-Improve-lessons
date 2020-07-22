#include <iostream>
using namespace std;
//三种常用的用类型定义结构体方法：
//1)定义类型的同时 定义变量：
struct student
{
	char name[10];
	int age;		
}s1,s2;
//2)匿名类型 定义变量
struct
{
	char name[20];
	int age;
}s3,s4;
//3)typedef:
typedef struct student1
{
	char name[10];
	int age;
}god;
god qwer;
student1 qwert;
//==============================

//本sin作废20200722

int main()
{

}