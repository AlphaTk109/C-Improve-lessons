//Author:���壨2194021500��
//�ļ�����������
#ifndef _EXP_1_H
#define _EXP_1_H
//����ڵ�:
typedef struct LNode							//0������ڵ�ṹ��
{
	int data;								//�ڵ�����
	struct LNode* next;						//ָ�룺ָ����һ�ڵ�
}LinkNode;									//����

//����������
//ʵ��ָ��Ҫ������
LinkNode* Init_List(void);						//1����ʼ������
void Delete_List(LinkNode**, int, int*);		//2��ɾ���ڵ�
void Insert_List(LinkNode**, int, int);			//3������ڵ�
void Destroy_List(LinkNode**);					//4����������
void Search_List(LinkNode*, int, int*);			//5�����ҽڵ�
void Prt_List(LinkNode*);						//6����ӡ�ڵ�
int List_Length(LinkNode* L);					//7�������Ա���
//�Զ��庯�����߼���ǿ
void push_list(LinkNode**, int);				//8����ָ��λ�ò�������
void push_back(LinkNode**, int);				//9�����βλ�ò�������
//���Ժ�����
void default_test();							//Ĭ�ϲ��Ժ���
#endif