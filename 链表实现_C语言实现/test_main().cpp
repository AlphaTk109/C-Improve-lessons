//Author:李金峰（2194021500）
//文件：测试文件 main()
//环境：Visual Stdio 2019
#include <stdio.h>		//载入C标准库 stdio.h
#include <stdlib.h>		//载入C标准库 stdlib.h
#include "exp1.h"		//载入文件 "exp1.h"

int main()
{
	default_test();
	return 0;
}

void default_test()//默认测试函数
{
	//0-初始化链表：
	LinkNode* myList = Init_List();
	//1-向链表尾端输入数据若干并打印输出：
	printf("链表测试1：初始化链表并向链表输入5个数据\n");
	for (int i = 1; i <= 5; i++) push_back(&myList, i);
	Prt_List(myList); system("pause"); system("cls");
	//2-向链表插入数据若干并打印输出：
	printf("链表测试2：向链表中插入4个数据\n");
	Insert_List(&myList, 1, 233);
	Insert_List(&myList, 3, 666);
	Insert_List(&myList, 5, 888);
	Insert_List(&myList, 7, 999);
	Prt_List(myList); system("pause"); system("cls");
	//3-将链表中部分数据删除若干并打印输出：
	printf("链表测试3-1：删除链表中数据1-5（无返回值）\n");
	for (int i = 1; i <= 5; i++) Delete_List(&myList, 1, NULL);
	Prt_List(myList); system("pause"); printf("\n\n\n");
	printf("链表测试3-2：删除链表中数据1（并输出返回值）\n");
	int return_data = 0;
	Delete_List(&myList, 1, &return_data);
	printf("被删除的数据为：%d\n", return_data);
	Prt_List(myList); system("pause"); system("cls");
	//4-查找链表中的数据：
	printf("链表测试4：查找链表中的数据 2\n");
	Search_List(myList, 2, &return_data);
	printf("数据%d的值为：%d\n", 2,return_data); printf("\n\n\n");
	printf("测试结束，链表已经摧毁\n");
	//5-摧毁链表
	Destroy_List(&myList);
	printf("测试结束，链表已经摧毁\n");

}