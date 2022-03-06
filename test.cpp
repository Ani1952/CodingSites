#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s, a, b;
		cin >> s;
		int n = s.length();
		for (int i = 0; i < n / 2; i++)
		{
			a += s[i];
			b += s[n -1 - i];
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		(a == b) ? cout << "YES" << endl : cout << "NO" << endl;
	}
	return 0;
}