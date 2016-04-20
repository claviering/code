#include<iostream>
#include<stack>
using namespace std;
int main()
{
	int n,i,count;
	int target[1000];
	stack<int> sk;
	while (cin >> n && n != 0)
	{
		while (cin >> target[0] && target[0])
		{
			for(i = 1; i < n; i++)
				cin >> target[i];
			count = 1;
			i = 0; 
			while (i < n)
			{
				if (count == target[i])
				{
					count++;
					i++;
				}
				else
				{
					if (!sk.empty() && sk.top() == target[i])
					{
						sk.pop();
						i++;
					}
					else
					{
						if (count <= n)
							sk.push (count++);
						else
							break;
					}
				}
			}
			if (i == n)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
			while (!sk.empty())
				sk.pop();
		}
		cout << endl;
	}
	return 0;
}
