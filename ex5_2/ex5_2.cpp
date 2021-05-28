#include <iostream>
using namespace std;
#define MAXN 20
// 问题表示
int n = 4; // 4种物品
int W = 6; // 限制重量为6
int w[] = { 0, 5, 3, 2, 1 };
int v[] = { 0, 4, 4, 3, 1 };
// 求解结果表示
int x[MAXN];  // 存放最终解
int maxv = 0; //  存放最优解的总价值

void dispasolution()
{
    cout << "选取重量为(";
    for (int j = 1; j <= n; j++)
        if (x[j] == 1)
            cout << w[j] << ",";
    cout << ")的物品" << endl;
    cout << "价值为：" << maxv;
}

void dfs(int i, int tw, int tv, int op[])
{
    if (i > n)
    {
        if (tw == W && tv > maxv)
        {
            maxv = tv;
            for (int j = 1; j <= n; j++)
                x[j] = op[j];
        }
    }
    else
    {
        op[i] = 1; //选取第i个物品
        dfs(i + 1, tw + w[i], tv + v[i], op);
        op[i] = 0; // 不选取第i个物品，回溯
        dfs(i + 1, tw, tv, op);
    }
}

int main()
{
    int op[MAXN];     // 存放临时解
    dfs(1, 0, 0, op); // i从1开始
    dispasolution();
    return 0;
}
