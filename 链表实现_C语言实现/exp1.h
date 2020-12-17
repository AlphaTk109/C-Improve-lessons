//Author:李金峰（2194021500）
//文件：函数声明
#ifndef _EXP_1_H
#define _EXP_1_H
//定义节点:
typedef struct LNode							//0）定义节点结构体
{
	int data;								//节点数据
	struct LNode* next;						//指针：指向下一节点
}LinkNode;									//别名

//函数声明：
//实验指导要求函数：
LinkNode* Init_List(void);						//1）初始化链表
void Delete_List(LinkNode**, int, int*);		//2）删除节点
void Insert_List(LinkNode**, int, int);			//3）插入节点
void Destroy_List(LinkNode**);					//4）销毁链表
void Search_List(LinkNode*, int, int*);			//5）查找节点
void Prt_List(LinkNode*);						//6）打印节点
int List_Length(LinkNode* L);					//7）求线性表长度
//自定义函数，逻辑增强
void push_list(LinkNode**, int);				//8）向指定位置插入数据
void push_back(LinkNode**, int);				//9）向表尾位置插入数据
//测试函数：
void default_test();							//默认测试函数
#endif