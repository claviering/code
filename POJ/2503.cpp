#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	string english;
	string foreign;
	map<string, string> m;
	while(1)
	{
		cin >> english >> foreign;
		m[foreign] = english;
		getchar();
		char c = getchar();
		if (c == '\n')
			break;
		ungetc(c, stdin);
	}

	while(cin >> foreign)
	{
		if(m[foreign] == "")
			cout << "eh" << endl;
		else
			cout << m[foreign] << endl;
	}
	return 0;
}