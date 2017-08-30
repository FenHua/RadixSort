// RadixSort.cpp : 定义控制台应用程序的入口点。
#include"iostream"
using namespace std;
int GetMaxDigit(int*a, int size)
{
	int base = 10;//标识数量级
	int digit = 1;//统计最大数据的位数
	for (int i = 0; i < size; i++)
	{
		while (a[i] >= base)
		{
			digit++;
			base *= 10;
		}
	}
	return digit;
}
void RadixSort(int*a,int size)
{
	int base = 1;
	int digit = GetMaxDigit(a, size);
	int*count = new int[10];
	int*start = new int[10];
	int*tmp = new int[size];
	while (digit--)
	{
		//统计数字出现的次数
		memset(count, 0, sizeof(int)* 10);
		for (int i = 0; i < size; i++)
		{
			count[(a[i] / base) % 10]++;
		}
		//求每组数据的起始位置
		start[0] = 0;
		for (int i = 1; i < 10; i++)
		{
			start[i] = start[i - 1] + count[i - 1];
		}
		//将数据写入tmp中
		for (int i = 0; i < size; i++)
		{
			int num = (a[i] / base) % 10;
			tmp[start[num]] = a[i];
			start[num]++;
		}
		//将tmp中的内容写入a中
		for (int i = 0; i < size; i++)
		{
			a[i] = tmp[i];
		}
		base *=10;
	}
	delete[]tmp;
}
int main()
{
	int a[] = { 73, 22, 93, 43, 55, 14, 28, 65, 39, 81 };
	RadixSort(a, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}