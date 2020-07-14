#include <iostream>
using namespace std;
#pragma warning (disable:4996)
//API指针法实现反转字符串
int inverse(char* str1)
{
	if (str1 == NULL) return -1;
	char* p1 = str1;
	char* p2 = str1 + strlen(str1) -1;
	while (p1 < p2)
	{
		char c = *p1;
		*p1 = *p2;
		*p2 = c;
		++p1;
		--p2;
	}
	return 0;
}
void main01()
{
	char buf[] = "abcdefg";
	inverse(buf);
	cout << buf;
}

