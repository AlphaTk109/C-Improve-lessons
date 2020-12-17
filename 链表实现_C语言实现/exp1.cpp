//Author:���壨2194021500��
//�ļ�������ʵ��
#include <stdio.h>										//����C��׼�� stdio.h
#include <stdlib.h>										//����C��׼�� stdlib.h
#include "exp1.h"										//�����ļ� "exp1.h" 

//1����ʼ������
LinkNode* Init_List(void)
{
	static LinkNode* head = NULL;						//��ȫ��������ͷ�ڵ�,��ָ��NULL�ڴ���
	return head;										//����ͷָ��				
}

//2��ɾ���ڵ�
void Delete_List(LinkNode** scan, int place, int* r_data)
{
	LinkNode* keep = *scan;								//��������ͷָ��
	if (place == 1) {									//���ɾ������ͷָ��
		if (r_data != NULL) *r_data = (*scan)->data;	//ͨ��һ��ָ�봫�ر�ɾ��������
		(*scan) = (*scan)->next;						//���µ�ͷָ��ָ��ڶ��ڵ�
		free(keep);										//�ͷ�ԭָ���ڴ���
		return;											//�Ƴ�������
	}
	for (int i = 1; i < place; i++)					//ѭ��ָ��ɾ���ڵ����һ�ڵ�
		(*scan) = (*scan)->next;
	LinkNode* temp = ((*scan)->next)->next;				//���汻ɾ���ڵ㱻��벿��
	if (r_data != NULL)	*r_data = ((*scan)->next)->data;//ͨ��һ��ָ�봫�ر�ɾ��������
	free((*scan)->next);								//�ͷ�ԭָ���ڴ���
	(*scan)->next = temp;								//�ӻغ�벿�ֵ�����
	if (keep != NULL) *scan = keep;						//�ָ�ͷָ���ָ��
}

//3��ָ��λ�ò���ڵ�
void Insert_List(LinkNode** scan, int place, int d)
{
	LinkNode* keep = *scan;								//��������ͷָ��
	for (int i = 0; i < place - 1; i++)					//ѭ��ָ�򱻲���ڵ����һ�ڵ�>1
		(*scan) = (*scan)->next;
	LinkNode* temp = (*scan)->next;						//������ʱ����temp���汻��벿��
	push_list(scan, d);									//��temp���¸�λ�ø�Ϊ�½ڵ�
	((*scan)->next)->next = temp;						//�ӻغ�벿�ֵ�����
	if (keep != NULL) *scan = keep;						//�ָ�ͷָ���ָ��
}

//4����������
void Destroy_List(LinkNode** pop)
{
	LinkNode* psave = NULL;								//������ʱָ�����
	while (*pop != NULL) {								//�������ǿ�
		psave = (*pop)->next;							//��ʱ����ָ����һ�ڵ�
		free(*pop);										//�ͷ���һ�ڵ�
		*pop = psave;									//�ָ�ָ��ָ��
	}
}

//5�����ҽڵ�
void Search_List(LinkNode* scan, int place, int* r_data)
{
	for (int i = 1; i < place; i++) scan = scan->next;	//ѭ��ָ�򱻲��ҽڵ�
	*r_data = scan->data;								//ͨ��һ��ָ�봫�ز�������
}

//6����ӡ�ڵ�
void Prt_List(LinkNode* head)
{
	int i = 1;											//������
	while (head != NULL) {								//ֻҪ����ǿ�
		printf("����%d   %d\n", i++, head->data);		//����ڵ�
		head = head->next;								//ָ����һ�ڵ�
	}
}

//7�������Ա���
int List_Length(LinkNode* temp)
{
	int i = 0;											//������
	while (temp != NULL) {								//ֻҪû�е����β
		i++;											//������+1
		temp = temp->next;								//ָ����һ�ڵ�
	}
	return i;											//���ؽڵ����� i
}

//8) ��temp��λ�÷����ڴ沢��������
void push_list(LinkNode** temp, int d)
{
	LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));	//�����ڴ�
	p->data = d; p->next = NULL;						//���ݵ���
	if ((*temp) == NULL)(*temp) = p;					//����ڱ�ͷ
	else (*temp)->next = p;								//��һ�ڵ�nextָ���µ��ڴ���
}

//9�����L��β��������
void push_back(LinkNode** scan, int d)
{
	LinkNode* keep = *scan;								//��������ͷָ��
	int length = List_Length(*scan) - 1;				//��ȡ��
	for (int i = 0; i < length; i++)					//ѭ��ָ���β
		(*scan) = (*scan)->next;
	push_list(scan, d);									//���β����ֵd
	if (keep != NULL) *scan = keep;						//�ָ�ͷָ���ָ��
}
