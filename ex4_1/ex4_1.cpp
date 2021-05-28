#include <iostream>
using namespace std;

//二进制数变化
void inc(int b[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (b[i])
		{ //将元素1改为0
			b[i] = 0;
		}
		else
		{ //将元素0改为1并退出for循环
			b[i] = 1;
			break;
		}
	}
}

//求幂集
void PSet(int a[], int b[], int n)
{
	int i, k;
	int pw = (int)pow(2, n); //求2的n次方
	cout << "1~" << n << "的幂集为：" << endl;

	for (i = 0; i < pw; i++)
	{
		cout << "{";
		for (k = 0; k < n; k++)
		{
			if (b[k])
			{ //输出二进制位中为1的所对应的{1,2,3..n}所在的位置的数
				cout << " " << a[k];
			}
		}
		cout << "}";
		inc(b, n); //变更二进制数
	}
	cout << endl;
}

int main()
{
	int n = 0;
	cout << "请输入n的数" << endl;
	cin >> n;
	int* a = new int[n]; //用数组a表示1-n的十进制数
	int* b = new int[n]; //用数组b表示二进制位
	for (int i = 0; i < n; i++)
	{
		a[i] = i + 1; //a初始化为1,2,3..n
		b[i] = 0;	  //b初始化为{0,0,0..}
	}
	PSet(a, b, n);

	return 0;
}