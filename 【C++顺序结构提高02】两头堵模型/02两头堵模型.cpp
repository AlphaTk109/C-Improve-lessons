#include <iostream>
using namespace std;
#pragma warning (disable:4996)

//API方法求非空格字符串长度
int getcount(char* str, int* pCount)
{
	char* p = str;
	int ncount = 0;
	if (str == NULL || pCount == NULL)
		return -1;
	int i = 0, j = 0;
	j = strlen(p) - 1;
	while (isspace(p[i]) && p[i] != '\0') i++;
	while (isspace(p[j]) && p[j] != '\0') j--;
	ncount = j - i + 1;
	*pCount = ncount;
	return 0;
}
void main01()
{
	char p[] = "    abcdefg    ";
	int num = 0;
	getcount(p, &num);
	cout << "count:" << num;
}
//去除字符串前后空格
int trimSpace(char* str, char* newstr)
{
	char* p = str;
	int ncount = 0;
	if (str == NULL || newstr == NULL)
		return -1;
	int i = 0, j = 0;
	j = strlen(p) - 1;
	while (isspace(p[i]) && p[i] != '\0') i++;
	while (isspace(p[j]) && p[j] != '\0') j--;
	ncount = j - i + 1;
	strncpy(newstr, str + i, ncount);
	newstr[ncount] = '\0';
	return 0;
}
void main02()
{
	char p[] = "    abcdefg       ";
	char buf[1024] = { 0 };
	int num = 0;
	trimSpace(p, buf);
	cout << "buf: " << buf << endl;
}

int main()//运行程序输出
{
	cout << "helloworld" << endl;
	main02();
	return 0;
}