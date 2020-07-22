#include <iostream>
using namespace std;
#pragma warning (disable :4996)
//将结果传出二级指针：
char** spit(char* buf1, char c, int count)
{
	char* p = NULL, * ptmp = NULL;
	int tmpcount = 0;
	char** myp = NULL;

	//精确分配内存：
		//1-第一编扫描出逗号个数：
	do
	{
		p = strchr(p, c);
		if (p != NULL)
			if (p - ptmp > 0)
			{
				tmpcount++;
				//让p ptmp达到下次检索的条件
				ptmp = p = p + 1;
			}
			else
				break;
	} while (*p != '\0');
	//2-根据行数精确分配内存：(第一维度)
	myp = (char**)malloc(tmpcount * sizeof(char*));
	if (myp == NULL) return NULL;
	//3-重新初始化并分配二维内存：
	//p与tmp的初始化
	tmpcount = 0;
	p = buf1;
	ptmp = buf1;

	do
	{
		p = strchr(p, c);
		if (p != NULL)
			if (p - ptmp > 0)
			{
				int len = p - ptmp + 1;
				myp[tmpcount] = (char*)malloc(len * sizeof(char));//分配二维内存
				if (myp[tmpcount] == NULL) return NULL;
				strncpy(myp[tmpcount], ptmp, p - ptmp);
				myp[tmpcount][p - ptmp] = '\0';
				tmpcount++;
				//让p ptmp达到下次检索的条件
				ptmp = p = p + 1;
			}
			else
				break;


	} while (*p != '\0');

	return myp;
}

int main()
{
	int ret = 0, i = 0, count=0;
	char p1[] = "abcde,acccce,ddddd,eeefe,32rerere,";
	char cTem = '\0';

	//=====char buf[10][30]
	char** p = NULL;

	p = spit(/*in*/p1,/*in*/cTem,/*out*/count);
	if (p == NULL)
	{
		cout << "function spitstring() err:" << ret;
	}
	for (i = 0;i < count;i++)
	{
		cout << p[i];
	}
	//释放内存
	for (i = 0;i < count ; i++)
	{
		free(p[i]);
	}
	free(p);
	return 0;
}



