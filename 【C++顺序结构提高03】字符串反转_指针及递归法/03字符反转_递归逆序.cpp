#include <iostream>
using namespace std;
#pragma warning (disable:4996)
//ͨ���ݹ�ķ�ʽ�������ӡ
//�ݹ��ȫ�ֱ�����������Ľ������ȫ�ֱ�����
//�ݹ�ͷ�ȫ�ֱ������ݹ�ָ��������������
int inverse02(char* p)
{
	if (p == NULL)//�ݹ�������쳣����
	{
		return -1;
	}
	if (*p == '\0')//�ݹ����������
	{
		return 0;
	}
	inverse02(p + 1);//�ݹ飬������Ϊֹ��û�����/��ӡ��ֻ����a-b-c...��ջ
	//�ȱ����õĺ�����ִ��
	cout << p;

}
int main02()
{
	char buf[] = "abcdefg";
	inverse02(buf);
	return 0;
}

//Api�ӿڷ���
int inverse(char *p,char *bufresult)
{
	if (p == NULL || bufresult == NULL) return -1;
	if (*p == '\0') return 0;
	inverse(p+1, bufresult);
	strncat(bufresult, p, 1);
}
int main03()
{
	char buf[] = "abcdefg";
	char mybuf[1024] = { 0 };
	inverse(buf, mybuf);
	cout << buf << endl;
	cout << mybuf << endl;
	return 0;
}


int main()
{
	main03();
	return 0;
}