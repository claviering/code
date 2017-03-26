/*
* 1到9选5个数排组合
*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

// 类似前序遍历，输出字符串，哈夫曼编码的输出
void dfs(int arr[], int x, int depth, string &s)
{
	string tmp = s;
	if (depth < 5)
	{
		for (int i = 0; i < 10; i++)
		{
			if(!arr[i])
			{
				arr[i] = 1;
				s += to_string(i);
				dfs(arr, i, depth + 1, s);
				arr[i] = 0;
				s = tmp;
			}
		}
	}
	else
		cout << s << endl;
}

int main()
{
	int arr[10];
	string s ="";
	memset(arr, 0, 40);
	dfs(arr, 0, 0, s);
	return 0;
}