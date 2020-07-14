#include <iostream>
using namespace std;

//使用while进行字符串查找
void main01()
{
	char p[200] = "1abcd11223344abcd2345abcd";
	char* p1 = p;
	int count = 0;
	while (p1 = strstr(p1, "abcd"))
	{
		count++;
		p1 += strlen("abcd");
		if (*p1 == '\0')break;
	}
	cout << "count:" << count << endl;
}
//定义API进行查找(尝试)
void api_main02(char *p, int *count1)
{
	while (p = strstr(p, "abcd"))
	{
		*count1+=1;
		p += strlen("abcd");
		if (*p == '/0') break;
	}
}
void main02()
{
	char p[] = "1abcd11223344abcd2345abcd";
	int count = 0;
	api_main02(p,&count);
	cout << count;
}
//定义api进行查找(答案)
int getcount(char* mystr/*in*/, char* sub/*in*/, int* ncount)
{
	char* p1 = mystr;//不要轻易改变形参的值
	int tmpcount = 0,ret=0;
	//优化：
	if (mystr == NULL || sub == NULL || ncount == NULL)
	{
		ret = -1;
		cout << "function getcount() err:" << ret << endl;
		return ret;
	}

	while (p1 = strstr(p1,sub))
	{
		tmpcount++;
		p1 += strlen("abcd");
		if (*p1 == '\0')break;
	}
	*ncount = tmpcount;//在最后进行间接赋值
	return 0;//0代表运行正确
}
int main03() 
{
	char p[] = "1abcd11223344abcd2345abcd";
	char sub[] = "abcd";
	int count = 0,ret=0;
	ret = getcount(p, sub, &count);
	if (ret != 0)
	{
		cout << "function getcount() err:" << ret;
		return ret;
	}
	cout << count;
}


void main()//运行函数
{
	main03();
}