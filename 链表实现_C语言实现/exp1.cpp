//Author:李金峰（2194021500）
//文件：功能实现
#include <stdio.h>										//载入C标准库 stdio.h
#include <stdlib.h>										//载入C标准库 stdlib.h
#include "exp1.h"										//载入文件 "exp1.h" 

//1）初始化链表
LinkNode* Init_List(void)
{
	static LinkNode* head = NULL;						//在全局区创建头节点,并指向NULL内存区
	return head;										//返回头指针				
}

//2）删除节点
void Delete_List(LinkNode** scan, int place, int* r_data)
{
	LinkNode* keep = *scan;								//保存链表头指针
	if (place == 1) {									//如果删除的是头指针
		if (r_data != NULL) *r_data = (*scan)->data;	//通过一级指针传回被删除的数据
		(*scan) = (*scan)->next;						//将新的头指针指向第二节点
		free(keep);										//释放原指针内存区
		return;											//推出函数体
	}
	for (int i = 1; i < place; i++)					//循环指向被删除节点的上一节点
		(*scan) = (*scan)->next;
	LinkNode* temp = ((*scan)->next)->next;				//保存被删除节点被后半部分
	if (r_data != NULL)	*r_data = ((*scan)->next)->data;//通过一级指针传回被删除的数据
	free((*scan)->next);								//释放原指针内存区
	(*scan)->next = temp;								//接回后半部分的数据
	if (keep != NULL) *scan = keep;						//恢复头指针的指向
}

//3）指定位置插入节点
void Insert_List(LinkNode** scan, int place, int d)
{
	LinkNode* keep = *scan;								//保存链表头指针
	for (int i = 0; i < place - 1; i++)					//循环指向被插入节点的上一节点>1
		(*scan) = (*scan)->next;
	LinkNode* temp = (*scan)->next;						//定义临时变量temp保存被后半部分
	push_list(scan, d);									//向temp的下个位置改为新节点
	((*scan)->next)->next = temp;						//接回后半部分的数据
	if (keep != NULL) *scan = keep;						//恢复头指针的指向
}

//4）销毁链表
void Destroy_List(LinkNode** pop)
{
	LinkNode* psave = NULL;								//定义临时指向变量
	while (*pop != NULL) {								//如果链表非空
		psave = (*pop)->next;							//临时变量指向下一节点
		free(*pop);										//释放上一节点
		*pop = psave;									//恢复指针指向
	}
}

//5）查找节点
void Search_List(LinkNode* scan, int place, int* r_data)
{
	for (int i = 1; i < place; i++) scan = scan->next;	//循环指向被查找节点
	*r_data = scan->data;								//通过一级指针传回查找数据
}

//6）打印节点
void Prt_List(LinkNode* head)
{
	int i = 1;											//计数器
	while (head != NULL) {								//只要链表非空
		printf("数据%d   %d\n", i++, head->data);		//输出节点
		head = head->next;								//指向下一节点
	}
}

//7）求线性表长度
int List_Length(LinkNode* temp)
{
	int i = 0;											//计数器
	while (temp != NULL) {								//只要没有到达表尾
		i++;											//计数器+1
		temp = temp->next;								//指向下一节点
	}
	return i;											//返回节点总数 i
}

//8) 向temp的位置分配内存并插入数据
void push_list(LinkNode** temp, int d)
{
	LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));	//分配内存
	p->data = d; p->next = NULL;						//数据导入
	if ((*temp) == NULL)(*temp) = p;					//如果在表头
	else (*temp)->next = p;								//上一节点next指向新的内存区
}

//9）向表L的尾插入数据
void push_back(LinkNode** scan, int d)
{
	LinkNode* keep = *scan;								//保存链表头指针
	int length = List_Length(*scan) - 1;				//获取表长
	for (int i = 0; i < length; i++)					//循环指向表尾
		(*scan) = (*scan)->next;
	push_list(scan, d);									//向表尾插入值d
	if (keep != NULL) *scan = keep;						//恢复头指针的指向
}
