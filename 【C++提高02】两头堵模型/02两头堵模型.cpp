#include <iostream>
using namespace std;

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


void main()//运行程序输出
{
	cout << "helloworld" << endl;
	main01();
}