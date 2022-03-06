#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[10000][4];
    int b[10000][4];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
            b[i][j] = a[i][j];
    }
    b[-1][0] = b[-1][1] = 0;
    for (int i = 0; i < n; i++)
    {
        b[i][0] = b[i][0] + b[i - 1][0];
        b[i][1] = b[i][1] + b[i - 1][1];
        if (b[i][0] > b[i][1])
            b[i][2] = 1;
        else
            b[i][2] = 2;
        b[i][3] = abs(b[i][0] - b[i][1]);
    }
    vector<int> vec;
    for (int i = 0; i < n; i++)
        vec.push_back(b[i][3]);

    int x = *max_element(vec.begin(), vec.end());

    for (int i = 0; i < n; i++)
    {
        if (b[i][3] == x)
            cout << b[i][2] << " " << b[i][3] << endl;
        break;
    }

    return 0;
}