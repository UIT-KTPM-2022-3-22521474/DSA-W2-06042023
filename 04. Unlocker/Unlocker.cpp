#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(const char a, const char b)
{
	return a > b;
}

int main()
{
	string s;
	cin >> s;
	sort(s.begin(), s.end(), cmp);
	int sum = 0;
	for (int i = 0; i < s.length(); i++)
		sum += (int)(s[i] - '0');
	if (sum % 3 == 1)
	{
		bool kt = false;
		int d = s.length() - 1;
		while (d >= 0)
		{
			if ((int)(s[d] - '0') % 3 == 1)
			{
				s.erase(s.begin() + d);
				kt = true;
				break;
			}
			d--;
		}
		if (kt == false)
		{
			d = s.length() - 1;
			int t = 2;
			while (d >= 0)
			{
				if ((int)(s[d] - '0') % 3 == 2)
				{
					s.erase(s.begin() + d);
					t--;
					if (t == 0)
						break;
				}
				d--;
			}
		}
	}
	if (sum % 3 == 2)
	{
		bool kt = false;
		int d = s.length() - 1;
		while (d >= 0)
		{
			if ((int)(s[d] - '0') % 3 == 2)
			{
				s.erase(s.begin() + d);
				kt = true;
				break;
			}
			d--;
		}
		if (kt == false)
		{
			d = s.length() - 1;
			int t = 2;
			while (d >= 0)
			{
				if ((int)(s[d] - '0') % 3 == 1)
				{
					s.erase(s.begin() + d);
					t--;
					if (t == 0)
						break;
				}
				d--;
			}

		}
	}
	cout << s;
	return 0;
}