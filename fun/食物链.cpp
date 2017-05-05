// 题目来源
// https://www.patest.cn/contests/gplt/L3-015
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

void dfs(string map_c[], int row, int n, vector<int> &result, bool flag[]) //map_c是表，row是开始的行数,整数n是球队
{
	int length = result.size();

	if(length == n)  //队伍数够了
	{
		int i = result[length-1]-1;
		int j = result[0]-1;
		bool end = map_c[i][j] == 'W' || map_c[j][i] == 'L';
		if (end)  //成环
		{
			cout << result[0];
			for (int k = 1; k < result.size(); k++)
				cout << " " << result[k];
			exit(0);
		}
		else
		{
			return;
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if(map_c[row][i] == 'W' || map_c[i][row] == 'L')
			{
				if(!flag[row])
					return;
				result.push_back(row+1);
				flag[row] = 0; //添加了改为0，添加了
				dfs(map_c, i, n, result, flag);
				result.pop_back();
				flag[row] = 1;
			}
		}
	}

}

bool check(string map_c[], int n)
{
	bool flag = 0;
	for (int i = 0; i < n; i++)
	{
		flag = 0;
		for (int j = 0; j < n; j++)
			if (map_c[i][j] == 'W')
				flag = 1;
		if(!flag)
			return 0;
	}
		
	return 1;
}

int main()
{
	int n,m;
	cin >> n;
	m=n;
	string map_char[20];

	int index = 0;
	while (n--)
	{
		string s;
		cin >> s;
		map_char[index++] = s;
	}

	bool flag[20];
	memset(flag,1,20);  //1标识球队有没有加入

	string result = "";
	vector<int> re;
	if(check(map_char,m))
	{
		dfs(map_char, 0, m, re, flag);
		cout << "No Solution";
	}
	else
		cout << "No Solution";

	return 0;
}
