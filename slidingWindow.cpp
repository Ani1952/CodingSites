#include <bits/stdc++.h>

using namespace std;

int slide(int *arr, int k)
{
    int n = sizeof(arr) / 4;
    int i, j, Max, c;
    Max = INT_MIN;
    for (i = 0; i < n - k + 1; i++)
    {
        c = 0;
        for (j = 0; j < k; j++)
            c = c + arr[i + j];
        Max = max(Max, c);
    }
    return Max;
}

int windowSlide(int *arr, int k)
{
    int n = sizeof(arr) / 4;
    queue<int> q;
    int i, j, Max, c;
    Max = INT_MIN;
    for (i = 0; i < n - k + 1; i++)
    {
        c = 0;
        for (j = 0; j < k; j++)
            q.push(arr[i + j]);
        while (!q.empty())
        {
            c = c + q.front();
            q.pop();
        }
        Max = max(Max, c);
    }
    return Max;
}

int main()
{

    return 0;
}