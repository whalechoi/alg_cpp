#include <iostream>
#include <vector>
#define PAC_MAX_VOL 10 //背包最大承重10

using namespace std;

void dfs(const vector<int> weights, const vector<int> vals, bool visit[], int currWeight, vector<int> seq);
void outputResult(vector<int> weights, vector<int> vals, bool visit[], int currWeight, vector<int> seq);

/**
*	使用递归的方式遍历所有的可能
*/
void dfs(const vector<int> weights, const vector<int> vals, bool visit[], int currWeight, vector<int> seq)
{
	for (int i = 0; i < 4; ++i)
	{
		if (!visit[i])
		{
			if (currWeight + weights[i] > PAC_MAX_VOL)
				continue;
			visit[i] = true;
			seq.push_back(i);										   //将当前步加入到序列中
			dfs(weights, vals, visit, (currWeight + weights[i]), seq); //基于当前状态深度遍历
			seq.erase(find(seq.begin(), seq.end(), i));				   //从序列中删除
			visit[i] = false;
		}
	}
	outputResult(weights, vals, visit, currWeight, seq);
	return;
}

/**
*	输出当前结果
*/
void outputResult(vector<int> weights, vector<int> vals, bool visit[], int currWeight, vector<int> seq)
{
	cout << "当前背包的重量是：" << currWeight << ", ";
	int sumVal = 0;
	for (int i = 0; i < 4; ++i)
		if (visit[i])
			sumVal += vals[i];
	cout << "当前背包的总价值为：" << sumVal << endl;
	cout << "当前结果集(编号)是：";
	for (auto ele : seq)
	{
		cout << ele << "  ";
	}
	cout << "\n-----------------------------" << endl;
}

int main()
{
	const vector<int> weights = { 7, 3, 4, 5 };  //各个物品的重量
	const vector<int> vals = { 42, 12, 40, 25 }; //各个物品的价值
	vector<int> seq;
	bool visit[4] = { false }; //用于在递归中表示当前已有哪些物品放在背包中了
	dfs(weights, vals, visit, 0, seq);
	return 0;
}
