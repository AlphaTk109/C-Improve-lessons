//Author:���壨2194021500��
//�ļ��������ļ� main()
//������Visual Stdio 2019
#include <stdio.h>		//����C��׼�� stdio.h
#include <stdlib.h>		//����C��׼�� stdlib.h
#include "exp1.h"		//�����ļ� "exp1.h"

int main()
{
	default_test();
	return 0;
}

void default_test()//Ĭ�ϲ��Ժ���
{
	//0-��ʼ������
	LinkNode* myList = Init_List();
	//1-������β�������������ɲ���ӡ�����
	printf("�������1����ʼ����������������5������\n");
	for (int i = 1; i <= 5; i++) push_back(&myList, i);
	Prt_List(myList); system("pause"); system("cls");
	//2-����������������ɲ���ӡ�����
	printf("�������2���������в���4������\n");
	Insert_List(&myList, 1, 233);
	Insert_List(&myList, 3, 666);
	Insert_List(&myList, 5, 888);
	Insert_List(&myList, 7, 999);
	Prt_List(myList); system("pause"); system("cls");
	//3-�������в�������ɾ�����ɲ���ӡ�����
	printf("�������3-1��ɾ������������1-5���޷���ֵ��\n");
	for (int i = 1; i <= 5; i++) Delete_List(&myList, 1, NULL);
	Prt_List(myList); system("pause"); printf("\n\n\n");
	printf("�������3-2��ɾ������������1�����������ֵ��\n");
	int return_data = 0;
	Delete_List(&myList, 1, &return_data);
	printf("��ɾ��������Ϊ��%d\n", return_data);
	Prt_List(myList); system("pause"); system("cls");
	//4-���������е����ݣ�
	printf("�������4�����������е����� 2\n");
	Search_List(myList, 2, &return_data);
	printf("����%d��ֵΪ��%d\n", 2,return_data); printf("\n\n\n");
	printf("���Խ����������Ѿ��ݻ�\n");
	//5-�ݻ�����
	Destroy_List(&myList);
	printf("���Խ����������Ѿ��ݻ�\n");

}