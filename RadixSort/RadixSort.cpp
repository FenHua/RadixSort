// RadixSort.cpp : �������̨Ӧ�ó������ڵ㡣
#include"iostream"
using namespace std;
int GetMaxDigit(int*a, int size)
{
	int base = 10;//��ʶ������
	int digit = 1;//ͳ��������ݵ�λ��
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
		//ͳ�����ֳ��ֵĴ���
		memset(count, 0, sizeof(int)* 10);
		for (int i = 0; i < size; i++)
		{
			count[(a[i] / base) % 10]++;
		}
		//��ÿ�����ݵ���ʼλ��
		start[0] = 0;
		for (int i = 1; i < 10; i++)
		{
			start[i] = start[i - 1] + count[i - 1];
		}
		//������д��tmp��
		for (int i = 0; i < size; i++)
		{
			int num = (a[i] / base) % 10;
			tmp[start[num]] = a[i];
			start[num]++;
		}
		//��tmp�е�����д��a��
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