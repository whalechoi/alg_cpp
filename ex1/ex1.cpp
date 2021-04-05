// ex1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

// 实验1：求无序序列中第k小的元素。
// 编写一个实验程序，利用STL中的priority_queue（优先队列）
// 求出一个无序整数序列中第k小的元素。

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int getlk(priority_queue<int, vector<int>, greater<int> > a, int k) {
	if (a.empty() || k > a.size() || k <= 0) {
		return NULL;
	}
	// 优先队列入队的时候会进行排序，所以直接返回第k个值即满足条件
	for (int i = 1; i < k; i++) {
		a.pop();
	}
	return a.top();
}


int main()
{
	// 优先队列 greater升序 less降序
	priority_queue<int, vector<int>, greater<int> > a;
	// 测试数据 5 2 0 1 3 1 4
	a.push(5);
	a.push(2);
	a.push(0);
	a.push(1);
	a.push(3);
	a.push(1);
	a.push(4);
	// 测试输出 0 1 1 2 3 4 5
	for (int i = 1; i <= a.size(); i++) {
		cout << getlk(a, i) << " ";
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
