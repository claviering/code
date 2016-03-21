#include <iostream>
#include <memory.h>
using namespace std;

int main()
{
	int TestCase, num, i, j, count;
	int cellnum[110];
	cin >> TestCase;
	while (TestCase--)
	{
		memset(cellnum, 0, sizeof(cellnum));
		count = 0;
		cin >> num;
		for (i = 1; i <= num; i++)
			for (j = 1; j <= num; j++)
			{
				if (j % i == 0)
				{
					if (cellnum[j] == 0)
						cellnum[j] = 1;
					else if (cellnum[j] == 1)
						cellnum[j] = 0;
				}
			}

		for (i = 1; i <= num; i++)
			if (cellnum[i] == 1)
				count++;
		cout << count << endl;
	}
}
