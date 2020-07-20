#include <iostream>
using namespace std;
#pragma warning (disable:4996)

int main001()
{
	int i = 0;
	char** p2 = NULL;
	char* tmp = NULL;
	int num = 5;
	p2 = (char **)malloc(sizeof(char*) * num);
	for (i = 0;i < num;i++)
	{
		p2[i] = (char*)malloc(sizeof(char) * 100);//char bu[100]
		sprintf(p2[i], "%d%d%d", i + 1, i + 1, i + 1);
	}
	cout << "before:" << endl;
	//排序前打印
	for (i = 0;i < num;i++)
	{
		cout << p2[i] << endl;
	}
	//排序
	for (i = 0;i < num;i++) 
	{
		for (int j = i + 1;j < num;j++) 
		{
			if (strcmp(p2[i], p2[j]) < 0)
			{
				tmp = p2[i];
				p2[i] = p2[j];
				p2[j] = tmp;
			}
		}
	}

	cout << "after:" << endl;
	//排序后打印
	for (i = 0;i < num;i++)
	{
		cout << p2[i]<<endl;
	}


	//释放内存
	for(i=0;i<num;i++)
	{
		if (p2[i] != NULL)
		{
			free(p2[i]);
			p2[i] = NULL;
		}
	}
	if (p2 != NULL)
	{
		free(p2);
	}
	return 0;
}
int main0001()
{
	main001();
	return 1;
}