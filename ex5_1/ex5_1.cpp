#include <cstdio>
#pragma warning(disable:4996)
using namespace std;

int C[50], tot = 0, n = 8, nc = 0;

void search(int cur)
{
	int i, j;
	nc++;
	if (cur == n)
	{ //递归边界。 只要走到了这里，所有皇后必然不冲突
		tot++;
	}
	else
		for (i = 0; i < n; i++)
		{
			int ok = 1;
			//尝试把第cur行的皇后放在第i列
			C[cur] = i;
			//检查是否和前面的皇后冲突
			for (j = 0; j < cur; j++)
				if (C[cur] == C[j] || cur - C[cur] == j - C[j] || cur + C[cur] == j + C[j])
				{
					ok = 0;
					break;
				}
			//如果合法，则继续递归
			if (ok)
				search(cur + 1);
		}
}

int main()
{
	scanf("%d", &n);
	search(0);
	printf("%d\n", tot);
	printf("%d\n", nc);
	return 0;
}