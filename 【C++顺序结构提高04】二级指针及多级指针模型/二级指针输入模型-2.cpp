#include <iostream>
using namespace std;
#pragma warning (disable:4996)
int spitstring(char* buf1, char c, char buf2[10][30], int* count)
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
				strncpy(buf2[tmpcount], ptmp, p - ptmp);
				buf2[tmpcount][p - ptmp] = '\0';
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
int main01()
{
	char p1[] = "abcdef,acccd,eeeee,aaaa,e34rere,sssss";
	char cTem = ',';
	char myarray[10][30];
	int ret,count, i = 0;
	ret=spitstring(p1, cTem, myarray, &count);
	if (ret != 0)
	{
		cout << "function spitstring() err:" << ret;
	}
	for (i = 0;i < count;i++)
	{
		cout << myarray[i];
	}
	return 0;
}