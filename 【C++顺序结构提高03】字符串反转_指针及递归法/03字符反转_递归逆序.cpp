#include <iostream>
using namespace std;
#pragma warning (disable:4996)
//通过递归的方式，逆向打印
//递归和全局变量（把逆序的结果存入全局变量）
//递归和非全局变量（递归指针做函数参数）
int inverse02(char* p)
{
	if (p == NULL)//递归结束的异常条件
	{
		return -1;
	}
	if (*p == '\0')//递归结束的条件
	{
		return 0;
	}
	inverse02(p + 1);//递归，到现在为止都没有输出/打印，只是让a-b-c...入栈
	//先被调用的函数后执行
	cout << p;

}
int main02()
{
	char buf[] = "abcdefg";
	inverse02(buf);
	return 0;
}

//Api接口法：
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