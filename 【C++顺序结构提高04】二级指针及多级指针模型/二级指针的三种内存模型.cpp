#include <iostream>
using namespace std;
#pragma warning (disable:4996)
int sort(const char** myp1, int num1, char(*myp2)[30], int num2, char*** myp3, int* num3)
{
	int i = 0, j = 0, k = 0, tmplen = 0, ret = 0;
	char** p3 = NULL;
	p3 = (char**)malloc((num1 + num2) * sizeof(char*));//里面装的是指针
	if (p3 == NULL)return -1;
	//根据大小精确分配内存
	for (i = 0;i < num1;i++)
	{
		tmplen = strlen(myp1[i]) + 1;
		p3[i] = (char*)malloc(tmplen * sizeof(char));
		if (p3[i] == NULL) return -2;
		strcpy(p3[i], myp1[i]);
	}
	for (j = 0;j < num2;j++)
	{
		tmplen = strlen(myp2[j]);
		p3[i] = (char*)malloc(tmplen * sizeof(char));
		if (p3[i] == NULL) return -3;
		strcpy(p3[i], myp2[j]);
		i++;
	}
	tmplen = num1 + num2;
	//排序：
	for (i = 0;i < tmplen;i++)
	{
		for (j = i + 1;j < tmplen;j++)
		{
			if (strcmp(p3[i], p3[j]) > 0)
			{
				char* tmp = p3[i];
				p3[i] = p3[j];
				p3[j] = tmp;
			}
		}
	}
	//间接赋值：
	*num3 = tmplen;
	*myp3 = p3;
	return ret;
}
void sortfree01(char** p, int len)
{
	if (p == NULL)
	{
		return;
	}
	for (int i = 0;i < len;i++)
	{
		free(p[i]);
	}
	free(p);
}
void sortfree02(char*** myp, int len)
{
	char** p = NULL;
	if (myp == NULL)
	{
		return;
	}
	p = *myp;//还原成二级指针
	if (p == NULL)
	{
		return;
	}
	for (int i = 0;i < len;i++)
	{
		free(p[i]);
	}
	free(p);
	*myp = NULL;
}
int main()
{
	const char* p1[] = { "aaa","cc1ccc","43434" };
	char buf2[10][30] = { "11s111","3ddddddd","66666666666666" };
	char** p3 = NULL;
	int len1, len2, len3;
	//len1 = sizeof(p1) / sizeof(*p1);
	len1 = sizeof(p1)/sizeof(*p1);
	len2 = 3;
	int ret = sort(p1, len1, buf2, len2, &p3, &len3);
	if (ret != 0)
	{
		cout << "function sort err:" << ret;
		return ret;
	}
	for (int i = 0;i < len3;i++)
	{
		cout << p3[i] << endl;;
	}
}