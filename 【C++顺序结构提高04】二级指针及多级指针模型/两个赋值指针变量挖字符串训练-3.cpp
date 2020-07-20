#include <iostream>
using namespace std;
#pragma warning (disable :4996)

//本程序存在尚未解决的问题
int spitspring2(char* buf1, char c, /*in*/char** myp, int* count)
{
	char* p = NULL, * ptmp = NULL;
	int tmpcount = 0;
	//p与tmp的初始化
	p = buf1;
	ptmp = buf1;
	do
	{
		p = strchr(p, c);
		if (p != NULL)
		{
			if (p - ptmp > 0)
			{
				strncpy(myp[tmpcount], ptmp, p - ptmp);
				myp[tmpcount][p - ptmp] = '\0';
				tmpcount++;
				//让p ptmp达到下次检索的条件
				ptmp = p = p + 1;
			}
		}
		else
		{
			break;
		}

	} while (*p != '\0');

	return 0;
}
int main02()
{
	int ret = 0, i = 0, count;
	char p1[] = "abcde,acccce,ddddd,eeefe,32rerere,";
	char cTem = '\0';

	//=====char buf[10][30]
	char** p = NULL;
		//先分配第一维度
	p = (char**)malloc(sizeof(char*) * 10);//char* array[10]
	if (p == NULL) return 0;
		//分配第二维度
	for (i = 0;i < 10;i++) p[i] = (char*)malloc(30 * sizeof(char));
	//=====char buf[10][30]

	ret = spitspring2(/*in*/p1,/*in*/cTem,/*out*/p,/*out*/&count);
	if (ret != 0)
	{
		cout << "function spitstring() err:" << ret;
	}
	for (i = 0;i < count;i++)
	{
		cout << p[i];
	}

	//释放内存
	for (i = 0;i < 10;i++)
	{
		free(p[i]);
	}
	free(p);

	return 0;
}
int main0000()
{
	return 0;
}