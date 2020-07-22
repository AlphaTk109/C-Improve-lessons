#include <iostream>
using namespace std;
int main51()
{
	//定义一个数组数据类型（注：int[5]与int不兼容）
	typedef int(myint5)[5];//等价于int[5]
	int i = 0;
	myint5 array;//array[5]
	for (i = 0;i < 5;i++) *(array + i) = i;
	for (i = 0;i < 5;i++) cout<<*(array + i)<<endl;
	cout << array<<endl;
	cout << (array + 1)<<endl;
	cout << &array << endl;
	cout << (&array + 1) << endl;
	return 0;
}
int main52()
{
	typedef int(*parray)[5];//通过数组定义数组指针：
	parray array;//二维
	int c[5] = { 0 };
	array = &c;
	for (int i = 0;i < 5;i++) **(array + i) = i;
	for (int i = 0;i < 5;i++) cout << **(array + i) << endl;
	return 0;
}

//定义数组指针变量的第三种方法：
int main53()
{
	int(*parray)[5];
	int c[5];
	int i = 0;
	parray = &c;
	for (i = 0;i < 5;i++) (*parray)[i] = i + 1;
	for (i = 0;i < 5;i++) cout << (*parray)[i] << endl;
	return 0;
}