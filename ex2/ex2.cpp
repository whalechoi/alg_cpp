// ex2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

// 实验2：出队第k个元素
// 编写一个实验程序，对于一个含有n(n>1)个元素的queue<int>队列容器qu
// 出队从队头到队尾的第k(1<=k<=n)个元素，其他队列元素不变；

#include <iostream>
#include <queue>
using namespace std;

int popk(queue<int>& qu, int k) {
	int size = qu.size();
	int result = NULL;
	for (int i = 1; i <= size; i++) {
		if (i != k) {
			// 不满足条件的值，出队后继续入队
			qu.push(qu.front());
			qu.pop();
		}
		else {
			result = qu.front();
			qu.pop();
		}
	}
	return result;
}

int main()
{
	queue<int> qu;
	// 测试数据 5 2 0 1 3 1 4
	qu.push(5);
	qu.push(2);
	qu.push(0);
	qu.push(1);
	qu.push(3);
	qu.push(1);
	qu.push(4);
	int size = qu.size();
	cout << "出队前队列为：";
	for (int i = 1; i <= size; i++) {
		cout << qu.front() << " ";
		qu.push(qu.front());
		qu.pop();
	}
	cout << endl << "出队的第5个数据值为：" << popk(qu, 5) << endl << "出队后队列为：";
	size = qu.size();
	for (int i = 1; i <= size; i++) {
		cout << qu.front() << " ";
		qu.pop();
	}
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
